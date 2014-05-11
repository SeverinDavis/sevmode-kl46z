/*
 * uc_pit.c
 *
 *  Created on: May 11, 2014
 *      Author: Severin
 */

#include "uc_pit.h"

void pit_enable(pit_t p_timer)
{}

void pit_disable(pit_t p_timer)
{}

void pit_init(pit_t p_timer, priority_t p_priority, int p_period)
{
	int_init(INT_PIT, p_priority);
}

void pit_set_callback(pit_t p_timer, callback_t p_callback)
{

}


//ISR
void PIT_IRQHandler()
{}
