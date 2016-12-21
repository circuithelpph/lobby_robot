void modeSelection(){
if (charComplete){
	switch(inputChar){
		case START_TEST_MODE:
			#ifdef DEBUG
			Serial.println("");
			Serial.println("TEST MODE INITIATED...............");
			Serial.println("*************************************");
			#endif
			
			changeModeLed(START_TEST_MODE);
			testMode();
			break;

		case START_LOW_POWER_MODE:
			#ifdef DEBUG
			Serial.println("");
			Serial.println("LOW POWER MODE INITIATED...............");
			Serial.println("*************************************");
			#endif
			
			changeModeLed(START_LOW_POWER_MODE);
			lowPowerMode();
			break;

		case START_AUTO_MODE:
			#ifdef DEBUG
			Serial.println("");
			Serial.println("AUTONOMOUS MODE INITIATED...............");
			Serial.println("*************************************");
			#endif
			
			changeModeLed(START_AUTO_MODE);
			autoMode();
			break;
		
		case START_CAMERA_MODE:
			#ifdef DEBUG
			Serial.println("");
			Serial.println("CAMERA MODE INITIATED...............");
			Serial.println("*************************************");
			#endif
		
			changeModeLed(START_CAMERA_MODE);
			cameraMode();
			break;

		case START_TALKING_MODE:
			#ifdef DEBUG
			Serial.println("");
			Serial.println("TALKING MODE INITIATED...............");
			Serial.println("*************************************");
			#endif
			
			changeModeLed(START_TALKING_MODE);
			talkingMode();
			break;
	}
}

}