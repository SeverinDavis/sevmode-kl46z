#include "uc_uart.c"

void uc_uart_init()
{
	SIM_SCGC4 |= 1 << 10;
	
}
