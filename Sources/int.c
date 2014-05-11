/*
 * int.c
 *
 *  Created on: May 10, 2014
 *      Author: Severin
 */

#include "int.h"

void int_init(IRQInterruptIndex p_vector, priority_t p_priority)
{
	int IRQ = p_vector - 16;
	NVIC_IP(IRQ % 4) &= ~(3 << ((8 * (IRQ % 4)) + 6));
	NVIC_IP(IRQ % 4) |= (p_priority << ((8 * (IRQ % 4)) + 6));
}
