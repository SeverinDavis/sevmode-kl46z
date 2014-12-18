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
volatile char move_mode = 'n';

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

void XBEE_CALLBACK()
{
	char rcv_mode = uc_uart_get_data();
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
	uc_spi_init(spi_0); // CAR_LED and CAR_MOTOR dependencies
	
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
	
	CAR_XBEE_init();
	
	uc_tpm_init();
	uc_tpm_set_callback(tpm_chan_2, CAR_MOTOR_CALLBACK_0);
	//uc_tpm_set_callback(tpm_chan_3, CAR_MOTOR_CALLBACK_1);
	//uc_tpm_set_callback(tpm_chan_4, CAR_MOTOR_CALLBACK_2);
	//uc_tpm_set_callback(tpm_chan_5, CAR_MOTOR_CALLBACK_3);
	int_all_unmask();
	
	CAR_MOTOR_motor_startup();	
}

void idle_mode()
{
	int i = 0;
	CAR_LED_set_color(car_led_2,car_led_wht);
	CAR_LED_set_color(car_led_3,car_led_wht);
	CAR_LED_set_color(car_led_0,car_led_red);
	CAR_LED_set_color(car_led_1,car_led_red);
	CAR_LED_update();
	while(idle == true)
	{
	
		CAR_LED_set_color(i,car_led_red);
		CAR_LED_set_color((i+1)%4,car_led_grn);
		CAR_LED_set_color((i+2)%4,car_led_red);
		CAR_LED_set_color((i+3)%4,car_led_grn);
		
		CAR_LED_update();
		uc_lptmr_delay(300);
		
		i=(i+1)%4;
	}
	CAR_LED_set_color(car_led_2,car_led_off);
	CAR_LED_update();

}

void run_mode()
{

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





