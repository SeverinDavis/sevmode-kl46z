#include "uc_uart.h"

void uc_uart_init()
{
	SIM_SCGC4 |= 1 << 10;
	
	//setting receiver interrupt enable
	UART0_C2 |= 1 << 5;
	//enable receiver
	UART0_C2 |= 1<< 2;
	
	//clock setup stuff
    MCG_C1 |= 0b11 << 1;
    MCG_C2 |= 1;
    
    SIM_SOPT2 |= SIM_SOPT2_UART0SRC(3);
	
}
