/*
 * uc_spi.c
 *
 *  Created on: June 15, 2014
 *      Author: Severin
 */


#include "uc_spi.h"



void uc_spi_init(spi_t p_spi)
{
	
	switch(p_spi)
	{
	case spi_0: 
		SIM_SCGC4 |= 1 << 22;
		SPI0_BR = 2 << 4;
		SPI0_BR |= 8;
		
		SPI0_C1 = SPI_C1_MSTR_MASK | SPI_C1_SSOE_MASK;
		
		//NEEDS GPIOS FOR CLK, MOSI, AND MISO
		//I'M TOO LAZY TO FIND THESE RIGHT NOW
		//gpio_port_init(port_D, pin_5, alt_2, output);
		//gpio_port_init(port_D, pin_6, alt_2, output);
		//gpio_port_init(port_D, pin_7, alt_2, output);
		
		SPI0_C1 |= 1 << 6;
		break;
		
	case spi_1:
		SIM_SCGC4 |= 1 << 23;
		SPI1_BR = 2 << 4;
		SPI1_BR |= 8;
		
		SPI1_C1 = SPI_C1_MSTR_MASK | SPI_C1_SSOE_MASK;

		gpio_port_init(port_D, pin_5, alt_2, output);
		gpio_port_init(port_D, pin_6, alt_2, output);
		gpio_port_init(port_D, pin_7, alt_2, output);

		SPI1_C1 |= 1 << 6;
		break;
		
	default:
		break;
		
	}
	
	

}

void uc_spi_send(spi_t p_spi, char p_char)
{
	
	switch(p_spi)
	{
	case spi_0:
		while(!(0b100000 & SPI0_S))  
		{} 
		SPI1_DL = p_char;
		while(!(0b100000 & SPI0_S))  
		{}
		break;
	
	case spi_1:
		while(!(0b100000 & SPI1_S))  
		{} 
		SPI1_DL = p_char;
		while(!(0b100000 & SPI1_S))  
		{}
		break;
	
	default:
		break;
	}
	
	
}
