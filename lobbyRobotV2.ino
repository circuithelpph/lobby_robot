/**************************************
Dentsu JS Lobby Robot
by: gHil / www.circuit-help.com.ph

Revision History
* 10/10/2016 - Build interface logic
	- Setting up different modes
	- added debug leds, mode option on board
	- gHiL
* 11/16/2016 - Switch to multi tab layout due to
	long lines of codes and for easier reading
	and clean setup of codes
	-gHiL

**************************************/



// setup parts
void setup(){
	// initiate serial communications with master
	Serial.begin(9600);
	waitForStartSignal();
	pixelsStart();	
	// set outputs	
	servoBegin();
	attachServos();
}

// *************************************
// main program loop

void loop(){
	serialEvent();
	modeSelection();			
}
