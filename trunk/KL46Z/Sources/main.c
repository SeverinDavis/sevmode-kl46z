/*
 * main.c
 *
 *  Created on: May 7, 2014
 *      Author: Severin
 */





#include "derivative.h" /* include peripheral declarations */
#include <gpio.h>


int main(void)
{
	int counter = 0;
	
	gpio_port_init(port_D, pin_5, alt_1, output);
	gpio_set_pin_state(port_D, pin_5, 0);
	gpio_set_pin_state(port_D, pin_5, 1);
	gpio_set_pin_state(port_D, pin_5, 1);
	gpio_set_pin_state(port_D, pin_5, 0);
	gpio_set_pin_state(port_D, pin_5, 1);
	gpio_set_pin_state(port_D, pin_5, 0);
	
	for(;;) {	   
	   	counter++;
	}
	
	return 0;
}
