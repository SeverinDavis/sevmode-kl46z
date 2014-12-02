/*
 * main.c
 *
 *  Created on: May 7, 2014
 *      Author: Severin
 */

#include "derivative.h" /* include peripheral declarations */
#include "uc_led.h"
#include "gpio.h"
#include "uc_lptmr.h"
#include "uc_dac.h"
#include "uc_pit.h"
#include "int.h"
#include "uc_spi.h"
#include "uc_tpm.h"
#include "uc_sw.h"
#include "CAR_LED.h"
#include "CAR_MOTOR.h"
#include "CAR_XBEE.h"
#include "custom.h"

volatile bool_t idle = true;


void PIT0_CALLBACK()
{
	uc_led_toggle(led_green);
}

void PIT1_CALLBACK()
{
	uc_led_toggle(led_red);
}

void SW1_CALLBACK()
{
	//toggle idle mode
	if(idle == true)
	{
		idle = false;
	}
	else if(idle == false)
	{
		idle = true;
	}
}

void SW3_CALLBACK()
{
	uc_led_toggle(led_green);
}



void clock_init()
{
	//set clock to blazing speed of 48Mhz. 
	//Timers won't run at right frequency unless this is called first.
	unsigned int set_clock= (MCG_C4 & ~0xE0) | 0xA0;
	MCG_C4 = set_clock;
}

void init()
{
	//mask all interrupts
	int_all_mask();
	
	//setup clock frequency
	clock_init();
	
	//setup spi
	//uc_spi_init(spi_0); // CAR_LED and CAR_MOTOR dependencies
	
	//init board leds
	uc_led_all_init();
	
	//init car leds
	CAR_LED_init();
	
	//switches configured for interrupts
	uc_sw_init_int(switch_1, SW1_CALLBACK);
	uc_sw_init_int(switch_3, SW3_CALLBACK);
	//
	CAR_MOTOR_manual_debug_init();
	uc_lptmr_init();
	//uc_tpm_init();
	//uc_tpm_set_callback(tpm_chan_2, CAR_MOTOR_CALLBACK_0);
	//uc_tpm_set_callback(tpm_chan_3, CAR_MOTOR_CALLBACK_1);
	//uc_tpm_set_callback(tpm_chan_4, CAR_MOTOR_CALLBACK_2);
	//uc_tpm_set_callback(tpm_chan_5, CAR_MOTOR_CALLBACK_3);
	int_all_unmask();
}

void idle_mode()
{
	while(idle == true)
	{
		uc_lptmr_delay(50);
		uc_led_toggle(led_green);
	}
	uc_led_off(led_green);

}

void run_mode()
{
	while(idle == false)
	{
		CAR_MOTOR_motor_startup();	
	}
}

int main(void)
{
	
	//initialize hardware
	init();


	
	while(1)
	{
		if(idle == true)
		{
			
			idle_mode();
		}
			
		if(idle == false)
		{
			run_mode();
		}
	}
	return 0;
}





