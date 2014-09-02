#include <Windows.h>
#include <xinput.h>
#include <stdio.h>
#include <time.h> 
#include <string>
#include <iostream>

#include "Serial.h"

#define BAUDRATE 9600

//#define XBOX

using namespace std;
void prompt_serial(CSerial * port_pntr);
void prompt_controller(XINPUT_STATE * state);
void run(XINPUT_STATE * state, CSerial * port_pntr);
void sleep(unsigned int mseconds); 

void main()
{
	

	CSerial port;
	prompt_serial(&port);
	
	XINPUT_STATE state;
#ifndef XBOX
	prompt_controller(&state);
#endif
	run(&state, &port);

		XINPUT_VIBRATION vibrate;
						vibrate.wLeftMotorSpeed = 23000;
				vibrate.wRightMotorSpeed = 0;

	for(;;)
	{
		XInputGetState(0, &state);

		if(state.Gamepad.wButtons & 0x0001)
			{
				cout << "UP is pressed" << endl;
				vibrate.wLeftMotorSpeed = 23000;
				vibrate.wRightMotorSpeed = 0;
				XInputSetState(0, &vibrate);
			}
		if(state.Gamepad.wButtons & 0x0002)
			{
				cout << "DOWN is pressed" << endl;
				vibrate.wLeftMotorSpeed = 0;
				vibrate.wRightMotorSpeed = 0;
				XInputSetState(0, &vibrate);
			}
		if(state.Gamepad.wButtons & 0x0004)
			{
				cout << "LEFT is pressed" << endl;
			}
		if(state.Gamepad.wButtons & 0x0008)
			{
				cout << "RIGHT is pressed" << endl;
			}
		if(state.Gamepad.wButtons & 0x0010)
			{
				cout << "START is pressed" << endl;
			}
		if(state.Gamepad.wButtons & 0x0020)
			{
				cout << "BACK is pressed" << endl;
			}
		if(state.Gamepad.wButtons & 0x0040)
			{
				cout << "LTHMB is pressed" << endl;
			}
		if(state.Gamepad.wButtons & 0x0080)
			{
				cout << "RTHMB is pressed" << endl;
			}
		if(state.Gamepad.wButtons & 0x0100)
			{
				cout << "LSHLDR is pressed" << endl;
			}
		if(state.Gamepad.wButtons & 0x0200)
			{
				cout << "RSHLDR is pressed" << endl;
			}
		if(state.Gamepad.wButtons & 0x1000)
			{

				cout << "A is pressed" << endl;
				vibrate.wLeftMotorSpeed = vibrate.wLeftMotorSpeed + 1000;
				vibrate.wRightMotorSpeed = 0;
				XInputSetState(0, &vibrate);
			}
		if(state.Gamepad.wButtons & 0x2000)
			{
				cout << "B is pressed" << endl;
				vibrate.wLeftMotorSpeed = 0;
				vibrate.wRightMotorSpeed = vibrate.wRightMotorSpeed + 1000;
				XInputSetState(0, &vibrate);

			}
		if(state.Gamepad.wButtons & 0x4000)
			{
				cout << "X is pressed" << endl;
			}
		if(state.Gamepad.wButtons & 0x8000)
			{
				cout << "Y is pressed" << endl;
			}

		if(state.Gamepad.bLeftTrigger > XINPUT_GAMEPAD_TRIGGER_THRESHOLD )
			{
				cout << "LT is pressed" << endl;
			}
		if(state.Gamepad.bRightTrigger > XINPUT_GAMEPAD_TRIGGER_THRESHOLD )
			{
				cout << "RT is pressed" << endl;
			}
		if(abs(state.Gamepad.sThumbLX) > XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE)
			{
				cout << "Left Thumbstick X Position is at" << state.Gamepad.sThumbLX << endl;
			}
		if(abs(state.Gamepad.sThumbLY) > XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE)
			{
				cout << "Left Thumbstick Y Position is at" << state.Gamepad.sThumbLY << endl;
			}
		if(abs(state.Gamepad.sThumbRX) > XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE)
			{
				cout << "Right Thumbstick X Position is at" << state.Gamepad.sThumbRX << endl;
			}
		if(abs(state.Gamepad.sThumbRY) > XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE)
			{
				cout << "Right Thumbstick Y Position is at" << state.Gamepad.sThumbRY << endl;
			}



		sleep(10);
	
	}

	return;
}

void run(XINPUT_STATE * state, CSerial * port_pntr)
{
	char mssg[6] = "Hello";
	mssg[0] = 'B';
	mssg[5] = 'C';
	cout << port_pntr->SendData(mssg, 6);
	system("pause");
}

void sleep(unsigned int mseconds) 
{ 
	clock_t goal = mseconds + clock(); 
	while (goal > clock()); 
}


void prompt_controller(XINPUT_STATE * state)
{

	//loops while no response from controller

	while( XInputGetState( 0, state ) != ERROR_SUCCESS )
	{
        cout << "Controller not connected" << endl << endl;
		system("pause");
	}

	//rechecks controller response
	if(XInputGetState( 0, state ) == ERROR_SUCCESS)
	cout << "Controller connected" << endl;
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