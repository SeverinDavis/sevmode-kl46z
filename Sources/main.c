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
	//set clock to blazing speed of 24Mhz. 
	//Timers won't run at right frequency unless this is called first.
	unsigned int set_clock= (MCG_C4 & ~0xE0) | 0xA0;
	MCG_C4 = set_clock;
}

void init()
{
	clock_init();
	uc_spi_init(spi_0); // CAR_LED and CAR_MOTOR dependencies
	uc_led_all_init();
	CAR_LED_init();
	CAR_MOTOR_manual_debug_init();
	uc_lptmr_init();
}

int main(void)
{
	init();
	
	while(1)
	{

		uc_lptmr_delay(50);

		CAR_MOTOR_update();
	}

		uc_led_on(led_green);

while(1)
{}
	return 0;
}



