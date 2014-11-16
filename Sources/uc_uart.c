#include "uc_uart.h"
#include "uc_led.h"

static callback_t uart0_callback = 0;

void uc_uart_init()
{	//clock setup stuff
    MCG_C1 |= 0b11 << 1;
    MCG_C2 |= 1;
    
	SIM_SCGC4 |= 1 << 10;
	
	//baud rate. MCGIRCLK=2000000, OSR default = 15.
	//MCGIRCLK/((OSR+1) (13)) = 9600
	UART0_BDL = (unsigned char) 13;
	//clear relevant bits in BDH
	UART0_BDH &= 0xE0;
	UART0_BDH |= (unsigned char)((~0xE0)&(13 >> 8));
	
	//enable receiver
	UART0_C2 |= 1 << 2;
	
	//setting receiver interrupt enable
	UART0_C2 |= 1 << 5;

	
	
	
	//configuring interrupt. HARDCODED PRIORITY. MAY NEED CHANGING
    int_init(INT_UART0, priority_1);
    

    SIM_SOPT2 |= SIM_SOPT2_UART0SRC(3);
}

void UART0_IRQHandler()
{
	//uc_led_on(led_red);
	if(uart0_callback)
	{
		uart0_callback();	
	}
	else
	{
		//dummy read to clear interrupt status. data lost.
		unsigned char dummy_read = UART0_D;
		
		//testing stuff for uart.
		if(dummy_read == 'A')
		{
			uc_led_on(led_red);
		}
		if(dummy_read =='B')
		{
			uc_led_off(led_red);
			
		}
	}
}
