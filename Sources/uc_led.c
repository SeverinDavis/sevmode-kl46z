#include "uc_led.h"


void uc_led_all_init()
{
	uc_led_init(led_red);
	uc_led_init(led_green);
}


void uc_led_init(led_t p_led)
{
	if(p_led == led_green)
	{
		gpio_port_init(port_D, pin_5, alt_1, output);
		gpio_set_pin_state(port_D, pin_5, 1);
	}
	else if(p_led == led_red)
	{
		gpio_port_init(port_E, pin_29, alt_1, output);
		gpio_set_pin_state(port_E, pin_29, 1);
		
	}
}


void uc_led_on(led_t p_led)
{
	if(p_led == led_green)
	{
		gpio_set_pin_state(port_D, pin_5, 0);
	}
	else if(p_led == led_red)
	{
		gpio_set_pin_state(port_E, pin_29, 0);
	}
		
}


void uc_led_off(led_t p_led)
{
	if(p_led == led_green)
	{
		gpio_set_pin_state(port_D, pin_5, 1);
	}
	else if(p_led == led_red)
	{
		gpio_set_pin_state(port_E, pin_29, 1);
	}
}


void uc_led_toggle(led_t p_led)
{
	if(p_led == led_green)
	{
		gpio_toggle_pin_state(port_D, pin_5);
	}
	else if(p_led == led_red)
	{
		gpio_toggle_pin_state(port_E, pin_29);
	}
}


