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


void PIT0_CALLBACK()
{
	uc_led_toggle(led_green);
}

void PIT1_CALLBACK()
{
	uc_led_toggle(led_red);
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
	int_all_mask();
	clock_init();
	uc_spi_init(spi_0); // CAR_LED and CAR_MOTOR dependencies
	uc_led_all_init();
	CAR_LED_init();
	CAR_MOTOR_manual_debug_init();
	uc_lptmr_init();
	uc_tpm_init();
	uc_tpm_set_callback(tpm_chan_2, PIT1_CALLBACK);
	int_all_unmask();
}

void motor_startup()
{
	//motor startup sequence
	//set a md and turn off output. enable chip.
	//update motors
	
	CAR_MOTOR_set_MD(step_2);
	CAR_MOTOR_set_output_en(disable);
	CAR_MOTOR_set_chip_en(enable);
	CAR_MOTOR_update();
	
	//start current limiting analog value
	CAR_MOTOR_set_current_limiter_en(enable);
	
	//reset chip, since it just intitialized
	//rst_cycle() auto-cycles and updates
	CAR_MOTOR_set_rst_cycle();
	
	//enable output
	CAR_MOTOR_set_output_en(enable);
	CAR_MOTOR_update();
}

int main(void)
{
	
	init();



	
	while(1)
	{
		//uc_led_toggle(led_red);
		uc_lptmr_delay(1000);

	}

		

while(1)
{}
	return 0;
}



