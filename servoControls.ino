#include <Servo.h>

Servo servoLeftArm;
Servo servoRightArm;

void servoBegin(){	
	servoLeftArm.write(MAX_ANGLE_SERVO);
	servoRightArm.write(MIN_ANGLE_SERVO);
}

void attachServos(){
	servoLeftArm.attach(PIN_SERVO_LEFT);
	servoRightArm.attach(PIN_SERVO_RIGHT);
}

void detachServos(){
	servoLeftArm.detach();
	servoRightArm.detach();
}

void servoWriteRightArm(uint16_t value){
	servoRightArm.write(value);
}

void servoWriteLeftArm(uint16_t value){
	servoLeftArm.write(value);
}