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

#define PCKT_NUM 9

volatile bool_t idle = true;
volatile char move_mode = 'n';
int switch_3_push = 0;
unsigned int switch_3_speed_hi = 50;
unsigned int switch_3_speed_lo = 150;
int xbee_pckt_cnt = 0;
char raw_pckts[PCKT_NUM] = {0,0,0,0,0,0,0,0,0}; 

int deadman = 0;


//has to run at lower rate than xbee callback
void PIT0_CALLBACK()
{
	if(deadman == 0)
	{
		//add shutdown code
	}
	else
	{
		deadman = 0;
	}
}

void PIT1_CALLBACK()
{

}

void SW1_CALLBACK()
{
	//toggle idle mode
	if(idle == true){

		idle = false;
	}
	else
	{
		idle = true;
	}
	
	
	//shutdown pit
	//xbee sleep
	//motor disable
	//set car status light
}

void SW3_CALLBACK()
{
	
	if(switch_3_push == 0)
	{
		switch_3_push = 1;
		CAR_MOTOR_set_t_direction(motor_0, 1);
		CAR_MOTOR_set_t_period(motor_0, 50);
		CAR_MOTOR_set_t_direction(motor_1, 1);
				CAR_MOTOR_set_t_period(motor_1, 50);
				CAR_MOTOR_set_t_direction(motor_2, 1);
						CAR_MOTOR_set_t_period(motor_2, 50);
						CAR_MOTOR_set_t_direction(motor_3, 1);
								CAR_MOTOR_set_t_period(motor_3, 50);

	}
	else if(switch_3_push == 1)
		{
			switch_3_push = 0;
			CAR_MOTOR_set_t_direction(motor_0, 0);
			CAR_MOTOR_set_t_direction(motor_1, 1);
			CAR_MOTOR_set_t_direction(motor_2, 1);
			CAR_MOTOR_set_t_direction(motor_3, 0);
		}
	
}

void XBEE_CALLBACK()
{
	deadman = 1;
	
	raw_pckts[xbee_pckt_cnt] = uc_uart_get_data();
	
	if(xbee_pckt_cnt == 8)
	{
		
	}
	
	xbee_pckt_cnt = (xbee_pckt_cnt + 1)%PCKT_NUM;
	 
	if(xbee_pckt_cnt == 0)
	{
		 //update actual from raw packet array
		 
	}
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
	CAR_LED_set_color(car_led_0, car_led_off);
	CAR_LED_set_color(car_led_1, car_led_off);
	CAR_LED_set_color(car_led_2, car_led_off);
	CAR_LED_set_color(car_led_3, car_led_off);
	CAR_LED_update();
	
	//switches configured for interrupts
	uc_sw_init_int(switch_1, SW1_CALLBACK);
	uc_sw_init_int(switch_3, SW3_CALLBACK);
	//
	CAR_MOTOR_manual_debug_init();
	uc_lptmr_init();
	
	CAR_XBEE_init();
	
	uc_tpm_init();
	uc_tpm_set_callback(tpm_chan_2, CAR_MOTOR_CALLBACK_0);
	uc_tpm_set_callback(tpm_chan_3, CAR_MOTOR_CALLBACK_1);
	uc_tpm_set_callback(tpm_chan_4, CAR_MOTOR_CALLBACK_2);
	uc_tpm_set_callback(tpm_chan_5, CAR_MOTOR_CALLBACK_3);
	int_all_unmask();
	
	CAR_MOTOR_motor_startup();	
}

void idle_mode()
{
	CAR_MOTOR_set_output_en(disable);
	CAR_MOTOR_update();

	while(idle == true)
	{}
	
}

void run_mode()
{
	CAR_MOTOR_set_output_en(enable);
	CAR_MOTOR_update();
	
	while(idle == false)
	{}
}

void accel_test()
{

}

int main(void)
{
	
	//initialize hardware
	init();
	



	//accel_test();
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





