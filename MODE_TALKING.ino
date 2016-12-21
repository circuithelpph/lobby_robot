// ****************************** Talking Mode ******************************
void talkingMode(){
	charComplete = false;
	digitalWrite(PIN_POWER_CONTROL, LOW);
	while (1){
		serialEvent();
		if (charComplete){
			if (inputChar == MOD_D_SERVO_MOVE){
				for (uint16_t x = MIN_ANGLE_SERVO; x < MAX_ANGLE_SERVO; x++){
					servoWriteRightArm(x);
					delay(10);
				}
				for (uint16_t x = MAX_ANGLE_SERVO; x > MIN_ANGLE_SERVO; x--){
					servoWriteRightArm(x);
					delay(10);
				}
				charComplete = false;
				inputChar = 'x';
			}
			else{
				digitalWrite(PIN_POWER_CONTROL, HIGH);
				break;
			}
		}
	}
}
