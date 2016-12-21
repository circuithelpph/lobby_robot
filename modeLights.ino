#include <Adafruit_NeoPixel.h>

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUM_PIXELS, PIN_MODE_INDICATOR, NEO_GRB + NEO_KHZ800);

void pixelsStart(){	
	pixels.begin();
}

void changeLight(uint8_t r, uint8_t g, uint8_t b){
	for(int i=0; i<NUM_PIXELS; i++){
		// pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
		pixels.setPixelColor(i, pixels.Color(r,g,b));
		
		// This sends the updated pixel color to the hardware.
		pixels.show();
	}
}

void changeModeLed(uint8_t mode){
	switch(mode){
		case START_LOW_POWER_MODE:
		// red
		changeLight(255, 0, 0);
		break;
		
		case START_AUTO_MODE:
		// green
		changeLight(0,255,0);
		break;
		
		case START_CAMERA_MODE:
		// blue
		changeLight(0,0,255);
		break;
		
		case START_TALKING_MODE:
		// deep pink
		changeLight(255, 20, 147);
		break;

		case START_TEST_MODE:
		changeLight(255, 215, 0);
		break;
	}
}