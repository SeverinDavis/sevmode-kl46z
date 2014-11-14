#include "uc_uart.h"
#include "uc_led.h"

static callback_t uart0_callback = 0;

void uc_uart_init()
{
	SIM_SCGC4 |= 1 << 10;
	
	//baud rate. afaik 24000000/9600 = 2500
	UART0_BDL = (unsigned char) 417;
	//clear relevant bits in BDH
	UART0_BDH &= 0xE0;
	UART0_BDH |= (unsigned char)((~0xE0)&(417 >> 8));
	
	//enable receiver
	UART0_C2 |= 1 << 2;
	
	//setting receiver interrupt enable
	UART0_C2 |= 1 << 5;

	
	
	
	//configuring interrupt. HARDCODED PRIORITY. MAY NEED CHANGING
    int_init(INT_UART0, priority_1);
    
	//clock setup stuff
    MCG_C1 |= 0b11 << 1;
    MCG_C2 |= 1;
    
    SIM_SOPT2 |= SIM_SOPT2_UART0SRC(3);
}

void UART0_IRQHandler()
{
	uc_led_on(led_red);
	if(uart0_callback)
	{
		uart0_callback();	
	}
	else
	{
		//dummy read to clear interrupt status. data lost.
		//unsigned char dummy_read = UART0_D;
	}
}
