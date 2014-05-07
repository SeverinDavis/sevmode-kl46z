/*
 * uc_led.h
 *
 *  Created on: Dec 24, 2013
 *      Author: Severin
 */

#ifndef UC_LED_H_
#define UC_LED_H_

#include "derivative.h"
#include "gpio.h"

typedef enum{
	green,
	red
} led;

void uc_led_init();
void uc_led_on(led p_led);
void uc_led_off(led p_led);
void uc_led_toggle(led p_led);

#endif /* UC_LED_H_ */
