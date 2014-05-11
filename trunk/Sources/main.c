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

void clock_init()
{
	unsigned int set_clock= (MCG_C4 & ~0xE0) | 0xA0;
	MCG_C4 = set_clock;
}

int main(void)
{
	clock_init();

	uc_led_all_init();
	uc_lptmr_init();
	
	while(1)
	{
		uc_led_toggle(led_green);
		uc_lptmr_delay(100);
	}
	return 0;
}
