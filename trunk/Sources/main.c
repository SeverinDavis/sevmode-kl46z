/*
 * main.c
 *
 *  Created on: May 7, 2014
 *      Author: Severin
 */





#include "derivative.h" /* include peripheral declarations */
#include "uc_led.h"
#include "gpio.h"

void clock_init()
{
	unsigned int set_clock= (MCG_C4 & ~0xE0) | 0xA0;
	MCG_C4 = set_clock;
}

int main(void)
{
	clock_init();
	int counter = 0;
	
	uc_led_all_init();
	
	uc_led_on(led_red);
	uc_led_off(led_red);
	uc_led_on(led_red);
	
	uc_led_toggle(led_red);
	uc_led_toggle(led_red);
	uc_led_toggle(led_red);
	
	for(;;) {	   
	   	counter++;
	}
	
	return 0;
}
