#include <Windows.h>
#include <xinput.h>
#include <stdio.h>
#include <time.h> 
#include <string>
#include <iostream>
#include <math.h>

#include "Serial.h"

#define BAUDRATE 9600
#define STOP_PERIOD 65535
#define MAX_PERIOD 65534.0
#define MIN_PERIOD 40.0
#define RTH_SCALER 4.0
#define PI 3.14159265

//#define XBOX_DEBUG
//#define RAW_VAL_PRINT
//#define RAW_MOTOR_PRINT
//#define PERIOD_PRINT
//#define PCKG_PRINT

using namespace std;
void prompt_serial(CSerial * port_pntr);
void prompt_controller(XINPUT_STATE * state);
void poll(XINPUT_STATE * state, CSerial * port_pntr);
void sleep(unsigned int mseconds); 
void xbox_debug_msg(XINPUT_STATE * p_state);
int compute_period(double raw_velocity);
void translate_and_send(int * m_period);

CSerial port;
double max_velocity;
double min_velocity;

void main()
{
	//connect to serial port
	prompt_serial(&port);
	XINPUT_STATE state;

	//connect to controller
	prompt_controller(&state);

	//get max and min velocities
	max_velocity = 1 / MIN_PERIOD;
	min_velocity = 1 / MAX_PERIOD; 
	
	while (1)
	{
		poll(&state, &port);
		sleep(200);
	}
}

/*
gets the angle of the thumbstick
*/
double get_theta(double x, double y)
{
	double theta = 0;
	//check that nothign is 0
	if (!((x == 0) && (y == 0)))
	{
		theta = atan2((double)y, (double)x);
	}

	if (y < 0)
	{
		theta = theta + (2 * PI);
	}

	return theta;
}

/*
gets magnitude of the thumbstick
*/
double get_mag(double x, double y)
{
	double y_sqrd = ((double)y)*((double)y);
	double x_sqrd = ((double)x)*((double)x);

	double mag = sqrt(x_sqrd + y_sqrd);

	//cap value at max
	if (mag > 32767)
	{
		mag = 32767;
	}
	return mag;
}

/*
polls the controller
*/
void poll(XINPUT_STATE * state, CSerial * port_pntr)
{
	//get controller state
	prompt_controller(state);

	#ifdef XBOX_DEBUG
		xbox_debug_msg(state);
	#endif

	double lmag = get_mag(state->Gamepad.sThumbLX, state->Gamepad.sThumbLY);
	double ltheta = get_theta(state->Gamepad.sThumbLX, state->Gamepad.sThumbLY);
	//only care about x coordinate on right thumbstick
	double rmag = state->Gamepad.sThumbRX;

	//check if lstick is within deadzone
	if (lmag < XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE)
	{
		lmag = 0;
		ltheta = 0;
	}
	else
	{
		//scale left magnitude to value between 0 and 1
		lmag = (lmag - XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE) / (32767 - XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE);
	}

	//check if rstick is within deadzone
	if (abs(rmag) < XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE)
	{
		rmag = 0;
	}
	else
	{
		if (rmag < -32767)
		{
			rmag = -32767;
		}
		//scale right magnitude o value between 0 and 1
		if (rmag > 0)
		{
			rmag = (rmag - XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE) / (32767 - XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE);
		}
		
		else if (rmag < 0)
		{
			rmag = (rmag + XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE) / (32767 - XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE);
		}
	}

#ifdef RAW_VAL_PRINT
	cout << "LTheta is: " << ltheta << endl;
	cout << "LMag is:" << lmag << endl;
	cout << "RMag is:" << rmag << endl << endl;
#endif 

	//scaled right thumb
	rmag = rmag / RTH_SCALER;

	double PI_div_4 = PI / 4;
	double sin_term = sin(ltheta + (PI_div_4));
	double cos_term = cos(ltheta + (PI_div_4));

	//construct raw motor velocities
	double raw_m0_vel = (lmag * cos_term) + rmag;
	double raw_m1_vel = (lmag * sin_term) + rmag;
	double raw_m2_vel = (lmag * sin_term) - rmag;
	double raw_m3_vel = (lmag * cos_term) - rmag;

	//scale raw velocities to between 0 and 1
	raw_m0_vel = raw_m0_vel / (1 + (1/RTH_SCALER));
	raw_m1_vel = raw_m1_vel / (1 + (1/RTH_SCALER));
	raw_m2_vel = raw_m2_vel / (1 + (1/RTH_SCALER));
	raw_m3_vel = raw_m3_vel / (1 + (1/RTH_SCALER));

#ifdef RAW_MOTOR_PRINT
	cout << "m0:  " << raw_m0_vel << endl;
	cout << "m1:  " << raw_m1_vel << endl;
	cout << "m2:  " << raw_m2_vel << endl;
	cout << "m3:  " << raw_m3_vel << endl << endl;
#endif

	int m_period[4];

	//compute periods from raw
	m_period[0] = compute_period(raw_m0_vel);
	m_period[1] = compute_period(raw_m1_vel);
	m_period[2] = compute_period(raw_m2_vel);
	m_period[3] = compute_period(raw_m3_vel);

	//0 and 3 needs to be reversed
	m_period[0] *= -1;
	m_period[3] *= -1;

#ifdef PERIOD_PRINT
	cout << "m0_period:  " << m_period[0] << endl;
	cout << "m1_period:  " << m_period[1] << endl;
	cout << "m2_period:  " << m_period[2] << endl;
	cout << "m3_period:  " << m_period[3] << endl << endl;
#endif
	
	translate_and_send(m_period);
}

/*
sleeps for specified milliseconds
*/
void sleep(unsigned int mseconds) 
{ 
	clock_t goal = mseconds + clock(); 
	while (goal > clock()); 
}

/*
Attempts to connect to a controller
*/
void prompt_controller(XINPUT_STATE * state)
{
	int flag = 0;
	//loops while no response from controller

	while( XInputGetState( 0, state ) != ERROR_SUCCESS )
	{
		if (flag == 0)
		{
			cout << "Controller not connected" << endl << endl;
			flag = 1;
		}
	}

	if (flag == 1)
	{
		cout << "Controller connected" << endl;
	}
	
}

/*
Attempts to connect to serial port
*/
void prompt_serial(CSerial * port_pntr)
{
	//print available ports
	cout << "Available COM ports" << endl;

	//scans ports
	for(int i = 1; i < 20; i++)
	{
		if(port_pntr->Open(i, BAUDRATE))
		{
			port_pntr->Close();
			cout << i <<". " << "COM" << i << endl;
		}
	}

	cout << endl << endl;

	cout << "Enter port number" << endl;

	//gets port number
	int port_num;
	cin >> port_num;

	//checks if port number was valid, loops if it wasn't
	while(!port_pntr->Open(port_num, BAUDRATE))
	{
		cout << endl << "Invalid port" << endl;
		cout << "Enter port number" << endl;
		cin >> port_num;
	}

	//rechecks if port is valid, prints message
	if(port_pntr->Open(port_num, BAUDRATE))
	{
		cout << "Connected to COM" << port_num << " with " << BAUDRATE << " baud" << endl << endl;
	}
}

/*
just prints the xbox controller state
*/
void xbox_debug_msg(XINPUT_STATE * p_state)
{
	if (p_state->Gamepad.wButtons & 0x0001)
	{
		cout << "UP is pressed" << endl;
	}
	if (p_state->Gamepad.wButtons & 0x0002)
	{
		cout << "DOWN is pressed" << endl;
	}
	if (p_state->Gamepad.wButtons & 0x0004)
	{
		cout << "LEFT is pressed" << endl;
	}
	if (p_state->Gamepad.wButtons & 0x0008)
	{
		cout << "RIGHT is pressed" << endl;
	}
	if (p_state->Gamepad.wButtons & 0x0010)
	{
		cout << "START is pressed" << endl;
	}
	if (p_state->Gamepad.wButtons & 0x0020)
	{
		cout << "BACK is pressed" << endl;
	}
	if (p_state->Gamepad.wButtons & 0x0040)
	{
		cout << "LTHMB is pressed" << endl;
	}
	if (p_state->Gamepad.wButtons & 0x0080)
	{
		cout << "RTHMB is pressed" << endl;
	}
	if (p_state->Gamepad.wButtons & 0x0100)
	{
		cout << "LSHLDR is pressed" << endl;
	}
	if (p_state->Gamepad.wButtons & 0x0200)
	{
		cout << "RSHLDR is pressed" << endl;
	}
	if (p_state->Gamepad.wButtons & 0x1000)
	{
		cout << "A is pressed" << endl;
	}
	if (p_state->Gamepad.wButtons & 0x2000)
	{
		cout << "B is pressed" << endl;
	}
	if (p_state->Gamepad.wButtons & 0x4000)
	{
		cout << "X is pressed" << endl;
	}
	if (p_state->Gamepad.wButtons & 0x8000)
	{
		cout << "Y is pressed" << endl;
	}
	if (p_state->Gamepad.bLeftTrigger > XINPUT_GAMEPAD_TRIGGER_THRESHOLD)
	{
		cout << "LT is pressed" << endl;
	}
	if (p_state->Gamepad.bRightTrigger > XINPUT_GAMEPAD_TRIGGER_THRESHOLD)
	{
		cout << "RT is pressed" << endl;
	}
	if (abs(p_state->Gamepad.sThumbLX) > XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE)
	{
		cout << "Left Thumbstick X Position is at" << p_state->Gamepad.sThumbLX << endl;
	}
	if (abs(p_state->Gamepad.sThumbLY) > XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE)
	{
		cout << "Left Thumbstick Y Position is at" << p_state->Gamepad.sThumbLY << endl;
	}
	if (abs(p_state->Gamepad.sThumbRX) > XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE)
	{
		cout << "Right Thumbstick X Position is at" << p_state->Gamepad.sThumbRX << endl;
	}
	if (abs(p_state->Gamepad.sThumbRY) > XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE)
	{
		cout << "Right Thumbstick Y Position is at" << p_state->Gamepad.sThumbRY << endl;
	}
}

/*
computes period from given velocity
*/
int compute_period(double raw_velocity)
{
	if (raw_velocity == 0)
	{
		return STOP_PERIOD;
	}
	else
	{
		double vel_range = max_velocity - min_velocity;
		
		double vel_scaled = (raw_velocity * vel_range) + min_velocity;
		double period = 1 / vel_scaled; 
		return (int)period;
	}
}

/*
packages up the four motor periods and sends them via the seria port
*/
void translate_and_send(int * m_period)
{
	char packets[12] = {};
	int converted_packet = 0;
	packets[0] = 0;
	packets[1] = 0;

	for (int i = 0; i < 4; i++)
	{
		int converted_packet = m_period[i];
		if (m_period[i] < 0)
		{
			converted_packet = m_period[i] * -1;
		}
		else
		{
			packets[2] |= (1 << i);
		}
		packets[3 + (i * 2)] = converted_packet & 0xFF;
		packets[3 + (i * 2) + 1] = (converted_packet >> 8) & 0xFF;
	}
	packets[2] |= 0xA0;

	packets[11] = packets[2] ^ packets[3] ^ packets[4] ^ packets[5] ^ packets[6] ^ packets[7] ^ packets[8] ^ packets[9] ^ packets[10];

	for (int i = 0; i < 12; i++)
	{
		cout << i  << "     " << (int)packets[i] << endl;
	}
	cout << "sent " << port.SendData(packets, 12) << " packets"<< endl;


}