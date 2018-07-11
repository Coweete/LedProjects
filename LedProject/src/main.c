/**
 * \file
 *
 * \brief Empty user application template
 *
 */

/**
 * \mainpage User Application template doxygen documentation
 *
 * \par Empty user application template
 *
 * Bare minimum empty user application template
 *
 * \par Content
 *
 * -# Include the ASF header files (through asf.h)
 * -# "Insert system clock initialization code here" comment
 * -# Minimal main function that starts with a call to board_init()
 * -# "Insert application code here" comment
 *
 */
#include <asf.h>
#include <util/delay.h>
#include "Leds/LedFunctions.h"
#include "Input/btnInterrupt.h"
#include "uart/uart_communication.h"
#include "adc/adc_functions.h"

char String[]="Hello world!!\n";

int main (void)
{
	//sysclk_init();
	//board_init();
	//initLeds();
	//initBtns();
	USART_init();
	adc_init();
	
	while (1)
	{
	}
}
