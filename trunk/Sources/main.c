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

void clock_init()
{
	unsigned int set_clock= (MCG_C4 & ~0xE0) | 0xA0;
	MCG_C4 = set_clock;
}

int main(void)
{
	
	clock_init();
	uc_dac_init();
	uc_led_all_init();
	uc_lptmr_init();
	
	int a = 100;
	pit_init(0, priority_1, 0);
	while(1)
	{
		uc_led_toggle(led_red);

		uc_lptmr_delay(1000);
	}
	return 0;
}
