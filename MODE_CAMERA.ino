// ************************************* Camera Mode ************************************************
void cameraMode(){
	charComplete = false;
	stopMotors(MOT_STOP_DELAY);
	conservePower();
	detachServos();
	digitalWrite(PIN_POWER_CONTROL, LOW);
	while (1){
		serialEvent();
		if (charComplete){
			restorePower();
			attachServos();
			digitalWrite(PIN_POWER_CONTROL, HIGH);
			break;
		}
	}
}
