/*
 * uc_pit.c
 *
 *  Created on: May 11, 2014
 *      Author: Severin
 */

#include "uc_pit.h"
#include "uc_led.h"

void pit_enable(pit_t p_timer)
{
	
}

void pit_disable(pit_t p_timer)
{
	
}

void pit_init(pit_t p_timer, priority_t p_priority, int p_period)
{
	SIM_SCGC6 |= 1<<23;
	/*PIT_MCR &= ~(1 << 1);
	int_init(INT_PIT, p_priority);
	PIT_TCTRL0 |=0b11;*/
	
	// turn on PIT
	PIT_MCR = 0x00;
	int_all_unmask();
	NVIC_ICPR |= 1 << ((INT_PIT - 16) % 32);
	NVIC_ISER |= 1 << ((INT_PIT - 16) % 32);
	int_init(INT_PIT, p_priority);
	// Timer 1
	PIT_LDVAL0 = 24000000; // setup timer 1 for 256000 cycles
	PIT_TCTRL0 |=0b11;

}

void pit_set_callback(pit_t p_timer, callback_t p_callback)
{

}


//ISR
void PIT_IRQHandler()
{
	PIT_TFLG0 = 1;
	
	uc_led_toggle(led_green);
}
