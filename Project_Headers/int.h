/*
 * int.h
 *
 *  Created on: May 10, 2014
 *      Author: Severin
 */

#ifndef INT_H_
#define INT_H_


typedef enum{
	DMA_0 	= 0,
	DMA_1 	= 1,
	DMA_2 	= 2,
	DMA_3 	= 3,
// unused	= 4,
	FTFA  	= 5,
	PMC   	= 6,
	LLWU  	= 7,
	I2C_0 	= 8,
	I2C_1 	= 9,
	SPI_0 	= 10,
	SPI_1 	= 11,
	UART_0 	= 12,
	UART_1	= 13,
	UART_2	= 14,
	ADC_0	= 15,
	CMP_0	= 16,
	TPM_0	= 17,
	TPM_1	= 18,
	TPM_2	= 19,
	RTC_Alrm= 20,
	RTC_Scnd= 21,
	PIT		= 22,
	I2S_0	= 23,
	USB_OTG = 24,
	DAC_0	= 25,
	TSI_0	= 26,
	MCG		= 27,
	LPTMR_0	= 28,
	SLCD	= 29,
	PORT_A	= 30,
	PORT_CD	= 31
} intsrc_t;


#endif /* INT_H_ */
