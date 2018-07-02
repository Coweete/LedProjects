/*
 * LedFunctions.c
 *
 * Created: 2018-07-01 21:40:37
 *  Author: User
 */ 
#include "LedFunctions.h"
#include "light_ws2812.h"

#define MAX_LEDS 29
#define COLORLENGTH (MAXPIX/2)
#define FADE (256/COLORLENGTH)

struct cRGB colors[8];
struct cRGB leds[MAX_LEDS];

void initLeds(){
	
		DDRB|= _BV(ws2812_pin);
		
		//Turn off all leds.
		ledsOff();
		
		// Creates the Rainbowcolors
	    colors[0].r=150; colors[0].g=150; colors[0].b=150;
	    colors[1].r=255; colors[1].g=000; colors[1].b=000;//red
	    colors[2].r=255; colors[2].g=100; colors[2].b=000;//orange
	    colors[3].r=100; colors[3].g=255; colors[3].b=000;//yellow
	    colors[4].r=000; colors[4].g=255; colors[4].b=000;//green
	    colors[5].r=000; colors[5].g=100; colors[5].b=255;//light blue (türkis)
	    colors[6].r=000; colors[6].g=000; colors[6].b=255;//blue
	    colors[7].r=100; colors[7].g=000; colors[7].b=255;//violet
		
		
}

void ledsOn(cRGB color){
	for (int i = MAX_LEDS; i > 0; i--)
	{
		leds[i-1].r = color.r;
		leds[i-1].g = color.g;
		leds[i-1].b = color.b;
	}
}

/************************************************************************/
/* Clears the strip                                                     */
/************************************************************************/
void ledsOff(){
	for (int i = MAX_LEDS; i > 0; i--)
	{
		leds[i-1].r = 0; 
		leds[i-1].g = 0;
		leds[i-1].b = 0;
	}
}

