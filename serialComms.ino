void waitForStartSignal(){
	while(1){
		serialEvent();
		if(charComplete){
			if (inputChar == START_ARDUINO_COMMAND){
				charComplete = false;
				break;
			}
			else{
				charComplete = false;
			}
		}
	}
	for (byte x = 0; x < sizeof(OUTPUT_PIN_ARRAY); x++){
		pinMode(OUTPUT_PIN_ARRAY[x], OUTPUT);
	}
}

void serialEvent(){
	while (Serial.available()){
		char inChar =  (char)Serial.read();
		#ifdef DEBUG
		Serial.println("");
		Serial.println(inChar, HEX);
		Serial.println(inChar);
		#endif
		
		if (inChar == '\n'){
			charComplete = true;
		}
		else{
			inputChar = inChar;
			charComplete = false;
		}
	}
}
