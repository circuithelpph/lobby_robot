// dc motor controls

// stopMotors
void stopMotors(unsigned long stoppingDelay){
	#ifdef DEBUG
	digitalWrite(PIN_MOVE_STRAIGHT_INDICATOR, LOW);
	digitalWrite(PIN_TURN_LEFT_INDICATOR, LOW);
	digitalWrite(PIN_TURN_RIGHT_INDICATOR, LOW);
	#endif
	
	// turn off directions pin
	digitalWrite(PIN_DIR_MOT_LEFT_FRONT, LOW);
	digitalWrite(PIN_DIR_MOT_RIGHT_FRONT, LOW);
	digitalWrite(PIN_DIR_MOT_LEFT_BACK, LOW);
	digitalWrite(PIN_DIR_MOT_RIGHT_BACK, LOW);

	// set speed pin to 0
	analogWrite(PIN_SPEED_MOT_LEFT_FRONT, 0);
	analogWrite(PIN_SPEED_MOT_RIGHT_FRONT, 0);
	analogWrite(PIN_SPEED_MOT_LEFT_BACK, 0);
	analogWrite(PIN_SPEED_MOT_RIGHT_BACK, 0);
	delay(stoppingDelay);
}

// advance
void moveForward(byte speed){
	#ifdef DEBUG
	digitalWrite(PIN_MOVE_STRAIGHT_INDICATOR, HIGH);
	digitalWrite(PIN_TURN_LEFT_INDICATOR, LOW);
	digitalWrite(PIN_TURN_RIGHT_INDICATOR, LOW);
	#endif
	
	digitalWrite(PIN_DIR_MOT_LEFT_FRONT, FWD_MOT_LEFT);
	digitalWrite(PIN_DIR_MOT_RIGHT_FRONT, FWD_MOT_LEFT);
	digitalWrite(PIN_DIR_MOT_LEFT_BACK, FWD_MOT_RIGHT);
	digitalWrite(PIN_DIR_MOT_RIGHT_BACK, FWD_MOT_RIGHT);

	analogWrite(PIN_SPEED_MOT_LEFT_FRONT, speed);
	analogWrite(PIN_SPEED_MOT_RIGHT_FRONT, speed);
	analogWrite(PIN_SPEED_MOT_LEFT_BACK, speed);
	analogWrite(PIN_SPEED_MOT_RIGHT_BACK, speed);
}

// turning left
void turnLeft(byte speedL, byte speedR){
	#ifdef DEBUG
	digitalWrite(PIN_MOVE_STRAIGHT_INDICATOR, LOW);
	digitalWrite(PIN_TURN_LEFT_INDICATOR, HIGH);
	digitalWrite(PIN_TURN_RIGHT_INDICATOR, LOW);
	#endif
	
	digitalWrite(PIN_DIR_MOT_LEFT_FRONT, !FWD_MOT_LEFT);
	digitalWrite(PIN_DIR_MOT_RIGHT_FRONT, FWD_MOT_RIGHT);
	digitalWrite(PIN_DIR_MOT_LEFT_BACK, !FWD_MOT_LEFT);
	digitalWrite(PIN_DIR_MOT_RIGHT_BACK, FWD_MOT_RIGHT);

	analogWrite(PIN_SPEED_MOT_LEFT_FRONT, speedL);
	analogWrite(PIN_SPEED_MOT_RIGHT_FRONT, speedR);
	analogWrite(PIN_SPEED_MOT_LEFT_BACK, speedL);
	analogWrite(PIN_SPEED_MOT_RIGHT_BACK, speedR);
}

// turning right
void turnRight(byte speedL, byte speedR){
	#ifdef DEBUG
	digitalWrite(PIN_MOVE_STRAIGHT_INDICATOR, LOW);
	digitalWrite(PIN_TURN_LEFT_INDICATOR, LOW);
	digitalWrite(PIN_TURN_RIGHT_INDICATOR, HIGH);
	#endif
	
	digitalWrite(PIN_DIR_MOT_LEFT_FRONT, FWD_MOT_LEFT);
	digitalWrite(PIN_DIR_MOT_RIGHT_FRONT, !FWD_MOT_RIGHT);
	digitalWrite(PIN_DIR_MOT_LEFT_BACK, FWD_MOT_LEFT);
	digitalWrite(PIN_DIR_MOT_RIGHT_BACK, !FWD_MOT_RIGHT);

	analogWrite(PIN_SPEED_MOT_LEFT_FRONT, speedL);
	analogWrite(PIN_SPEED_MOT_RIGHT_FRONT, speedR);
	analogWrite(PIN_SPEED_MOT_LEFT_BACK, speedL);
	analogWrite(PIN_SPEED_MOT_RIGHT_BACK, speedR);
}
