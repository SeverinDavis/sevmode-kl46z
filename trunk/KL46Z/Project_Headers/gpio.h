/*
 * gpio.h
 *
 *  Created on: May 7, 2014
 *      Author: Severin
 */

#include <derivative.h>

typedef enum{
	input,
	output	
} dir_t;

typedef enum{
	port_A,
	port_B,
	port_C,
	port_D,
	port_E,	
} port_t;

typedef enum{
	alt_0,
	alt_1,
	alt_2,
	alt_3,
	alt_4,
	alt_5,
	alt_6,
	alt_7	
} alt_t;

typedef enum{
	pin_0,
	pin_1,
	pin_2,
	pin_3,
	pin_4,
	pin_5,
	pin_6,
	pin_7,
	pin_8,
	pin_9,
	pin_10,
	pin_11,
	pin_12,
	pin_13,
	pin_14,
	pin_15,
	pin_16,
	pin_17,
	pin_18,
	pin_19,
	pin_20,
	pin_21,
	pin_22,
	pin_23,
	pin_24,
	pin_25,
	pin_26,
	pin_27,
	pin_28,
	pin_29,
	pin_30,
	pin_31,
} pin_t;


void gpio_pin_set_dir(port_t, pin_t, dir_t);
void gpio_pin_set_alt(port_t, pin_t, alt_t);
void gpio_port_init(port_t, pin_t, alt_t, dir_t);

int gpio_get_pin_state(port_t, pin_t);
void gpio_set_pin_state(port_t, pin_t, int);
void gpio_toggle_pin_state(port_t, pin_t);
