#include "uc_uart.h"

void uc_uart_init()
{
	SIM_SCGC4 |= 1 << 10;
	
}
