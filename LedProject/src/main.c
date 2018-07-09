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

int main (void)
{
	sysclk_init();
	board_init();
	//initBtns();
	
	DDRB |= (1 << PORTB5);
	
	while (1)
	{
		_delay_ms(1000);
		PORTB ^= (1 << PORTB5);
	}
}
