

/*
vibrate code example
XINPUT_VIBRATION vibrate;
vibrate.wLeftMotorSpeed = 23000;
vibrate.wRightMotorSpeed = 0;
XInputSetState(0, &vibrate);
*/

#include <Windows.h>
#include <xinput.h>
#include <stdio.h>
#include <time.h> 
#include <string>
#include <iostream>
#include <math.h>

#include "Serial.h"

#define BAUDRATE 9600

//#define XBOX_DEBUG
#define VAL_PRINT

#define PI 3.14159265

using namespace std;
void prompt_serial(CSerial * port_pntr);
void prompt_controller(XINPUT_STATE * state);
void poll(XINPUT_STATE * state, CSerial * port_pntr);
void sleep(unsigned int mseconds); 
void xbox_debug_msg(XINPUT_STATE * p_state);

void main()
{
	CSerial port;
	prompt_serial(&port);

	XINPUT_STATE state;

	prompt_controller(&state);

	while (1)
	{
		
		poll(&state, &port);
		sleep(50);
	}


}

void poll(XINPUT_STATE * state, CSerial * port_pntr)
{
	int x = 0;
	int y = 0;

	double theta = 0;
	double mag = 0;
	prompt_controller(state);

	#ifdef XBOX_DEBUG
		xbox_debug_msg(state);
	#endif


	
	x = (state->Gamepad.sThumbLX);
	y = (state->Gamepad.sThumbLY);
	if (!((x == 0) && (y == 0)))
	{
		theta = atan2((double)y, (double)x);
	}

	double y_sqrd = ((double)y)*((double)y);
	double x_sqrd = ((double)x)*((double)x);

	mag = sqrt(x_sqrd + y_sqrd);
	if (mag < XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE)
	{
		mag = 0;
		theta = 0;
	}
	else
	{
		if (mag > 32767)
		{
			mag = 32767;
		}
	
		if (y < 0)
		{
			theta = theta + (2*PI);
		}

		theta = (theta * 180) / PI;
		mag = (mag - XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE) / (32767 - XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE);
	}



	

#ifdef VAL_PRINT
	cout << "Theta is: " << theta << endl;
	cout << "Mag is:" << mag << endl << endl;
#endif

	double PI_div_4 = PI / 4;
	double sin_term = sin(theta + (PI_div_4));
	double cos_term = cos(theta + (PI_div_4));


	



	
}

void sleep(unsigned int mseconds) 
{ 
	clock_t goal = mseconds + clock(); 
	while (goal > clock()); 
}


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

void prompt_serial(CSerial * port_pntr)
{

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