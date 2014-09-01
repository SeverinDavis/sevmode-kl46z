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


void main()
{
	

	CSerial port;
	prompt_serial(&port);
	
	XINPUT_STATE state;
#ifndef XBOX
	prompt_controller(&state);
#endif
	run(&state, &port);

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