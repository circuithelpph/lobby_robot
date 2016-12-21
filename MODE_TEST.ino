
// ************************************* Test Mode ************************************************
void testMode(){
	digitalWrite(PIN_POWER_CONTROL, HIGH);
	#ifdef DEBUG
	Serial.println("Test initiated...");
	Serial.println("Testing Distance Sensor Channel A");
	#endif
	
	uint32_t t = 0;
	// IR Distance Sensor A
	t = millis();
	while (millis() - t < MAX_TEST_TIME ){
		readSamples(PIN_DIST_SENS_R);
		uint8_t sensAValue = takeAverage();
		
		#ifdef DEBUG
		Serial.println("Sensor A value: " + String (sensAValue));
		#endif
	}

	// IR Distance Sensor B
	#ifdef DEBUG
	Serial.println("");
	Serial.println("Testing Distance Sensor Channel B");
	#endif
	
	t = millis();
	while (millis() - t < MAX_TEST_TIME ){
		readSamples(PIN_DIST_SENS_M);
		uint8_t sensBValue = takeAverage();
		Serial.println("Sensor B value: " + String (sensBValue));
	}

	// IR Distance Sensor C
	#ifdef DEBUG
	Serial.println("");
	Serial.println("Testing Distance Sensor Channel C");
	#endif
	
	t = millis();
	while (millis() - t < MAX_TEST_TIME ){
		readSamples(PIN_DIST_SENS_L);
		uint8_t sensCValue = takeAverage();
		Serial.println("Sensor C value: " + String (sensCValue));
	}

	// motor left channel

	#ifdef DEBUG
	Serial.println("");
	Serial.println("Testing left motors");
	#endif
	
	turnLeft(MAX_MOT_TURNING_SPEED_LEFT, MAX_MOT_TURNING_SPEED_RIGHT);
	t = millis();
	while (millis() - t < MAX_TEST_TIME ){
	}

	stopMotors(MOT_STOP_DELAY);
	#ifdef DEBUG
	Serial.println("");
	Serial.println("Testing right motors");
	#endif
	
	turnRight(MAX_MOT_TURNING_SPEED_LEFT, MAX_MOT_TURNING_SPEED_RIGHT);
	t = millis();
	while (millis() - t < MAX_TEST_TIME ){
	}

	#ifdef DEBUG
	Serial.println("");
	Serial.println("Stopping motors");
	#endif
	
	stopMotors(MOT_STOP_DELAY);
	t = millis();
	while (millis() - t < MAX_TEST_TIME ){
	}

	#ifdef DEBUG
	Serial.println("");
	Serial.println("Testing left servo");
	#endif
	
	for (uint16_t x = MAX_ANGLE_SERVO; x > MIN_ANGLE_SERVO; x--){
		servoWriteLeftArm(x);
		delay(10);
	}
	for (uint16_t x = MIN_ANGLE_SERVO; x < MAX_ANGLE_SERVO; x++){
		servoWriteLeftArm(x);
		delay(10);
	}

	#ifdef DEBUG
	Serial.println("");
	Serial.println("Testing right servo");
	#endif
	
	for (uint16_t x = MIN_ANGLE_SERVO; x < MAX_ANGLE_SERVO; x++){
		servoWriteRightArm(x);
		delay(10);
	}
	for (uint16_t x = MAX_ANGLE_SERVO; x > MIN_ANGLE_SERVO; x--){
		servoWriteRightArm(x);
		delay(10);
	}
	
	#ifdef DEBUG
	Serial.println("");
	Serial.println("Testing Direction Leds...");
	#endif
	
	digitalWrite(PIN_TURN_LEFT_INDICATOR, HIGH);
	digitalWrite(PIN_TURN_RIGHT_INDICATOR, HIGH);
	digitalWrite(PIN_MOVE_STRAIGHT_INDICATOR, HIGH);
	delay(1000);
	digitalWrite(PIN_TURN_LEFT_INDICATOR, LOW);
	digitalWrite(PIN_TURN_RIGHT_INDICATOR, LOW);
	digitalWrite(PIN_MOVE_STRAIGHT_INDICATOR, LOW);
	
	#ifdef DEBUG
	Serial.println("");
	Serial.println("Testing Mode Led(s)...");
	#endif
	
	for(uint8_t x = 0; x < 255; x++){
		changeLight(x, 0, 0);
		delay(15);
	}
	for(uint8_t x = 0; x < 255; x++){
		changeLight(0, x, 0);
		delay(15);
	}
	for(uint8_t x = 0; x < 255; x++){
		changeLight(0, 0, x);
		delay(15);
	}
	changeLight(0,0,0);
	
	#ifdef DEBUG
	Serial.println("");
	Serial.println("Testing Completed...");
	Serial.println("*****************************************************");
	#endif
	
	Serial.println(CONTINUE);
	charComplete = false;
	inputChar = 'x';
}
