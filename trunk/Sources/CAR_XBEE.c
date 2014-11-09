/*
 * CAR_XBEE.c
 *
 *  Created on: November 9, 2014
 *      Author: Severin
 */
#include "CAR_XBEE.h"

void CAR_XBEE_init()
{
	//tx
	gpio_port_init(port_D, pin_7, alt_3, output);
	//rx
	gpio_port_init(port_D, pin_6, alt_3, input);	
	
	//on. Initialized to sleep state
	gpio_port_init(port_E, pin_20, alt_1, output);
	gpio_port_set_pin_state(port_E, pin_20, 0);
	
	//reset cycle
	gpio_port_init(port_E, pin_21, alt_1, output);
	CAR_XBEE_reset();
}



void CAR_XBEE_reset()
{
	gpio_port_set_pin_state(port_E, pin_21, 1);
	gpio_port_set_pin_state(port_E, pin_21, 0);
	gpio_port_set_pin_state(port_E, pin_21, 1);
}
