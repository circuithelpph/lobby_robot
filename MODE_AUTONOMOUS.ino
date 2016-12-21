//******************************* AUTO MODE ***************************************

void autoMode(){
	unsigned long tempT = 0;
	charComplete = false;
	digitalWrite(PIN_POWER_CONTROL, HIGH);
	// stabilize supply
	delay(100);
	changeLight(0,255,0);
  while(1){
    serialEvent();
    if (charComplete){
      if (inputChar == CONTINUE_AUTO){
        charComplete = false;
        inputChar = 'x';
        break;
      }
      else{
        break;
      }
    }
  }
	while(1){
		serialEvent();
		if (charComplete){
			stopMotors(0);
			if (inputChar == MOD_A_SERVO_MOVE){
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
				
				tempT = millis();
				boolean doExitCommand = false;
				while (1){
					serialEvent();
					if (charComplete){
						if (inputChar == CONTINUE){
							//turnRight(MAX_MOT_TURNING_SPEED_LEFT, MAX_MOT_TURNING_SPEED_RIGHT);
							//delay(1000);
							// Serial.println(CONTINUE);			
							charComplete = false;
							inputChar = 'x';							
							break;
						}
						else if (inputChar == MOD_A_SERVO_MOVE){
							break;
						}
						else{
							doExitCommand = true;							
							break;
						}
					}
				}
				
				// back to change mode
				if (doExitCommand){
					stopMotors(0);					
					#ifdef DEBUGLED
						digitalWrite(PIN_MOVE_STRAIGHT_INDICATOR, LOW);
						digitalWrite(PIN_TURN_LEFT_INDICATOR, LOW);
						digitalWrite(PIN_TURN_RIGHT_INDICATOR, LOW);
					#endif
					break;
				}
			}
			else if (inputChar == CONTINUE){
				// continue
			}
			
			else{
				#ifdef DEBUGLED
						digitalWrite(PIN_MOVE_STRAIGHT_INDICATOR, LOW);
						digitalWrite(PIN_TURN_LEFT_INDICATOR, LOW);
						digitalWrite(PIN_TURN_RIGHT_INDICATOR, LOW);
				#endif
				
				break;
			}
		}
		if (!charComplete){
      #ifdef DEBUG
        Serial.println("Moving forward");
			#endif
			moveForward(MAX_MOT_SPEED);
			for (uint8_t x = 0; x < NUM_OF_DIST_SENSORS; x++){
				readSamples(INPUT_PIN_ARRAY[x]);
				IR_SENSOR_ARRAY[x] = takeAverage();
				if (IR_SENSOR_ARRAY[x] < MAX_DIST_CENTER && IR_SENSOR_ARRAY[x] >= 10){
					switch (x){
						case 0:
              #ifdef DEBUG
                Serial.println("Right Sense: Turning Left");
              #endif
							turnRight(MAX_MOT_TURNING_SPEED_LEFT, MAX_MOT_TURNING_SPEED_LEFT_COMPENSATE);
							delay(MOT_TURNING_DELAY);
              stopMotors(500);
							break;
						case 1:
              #ifdef DEBUG
                Serial.println("Middle Sense: Turning Left");
              #endif
							turnRight(180, MAX_MOT_TURNING_SPEED_RIGHT);
							delay(MOT_TURNING_DELAY);
							stopMotors(500);
							break;
						case 2:
              #ifdef DEBUG
                Serial.println("Left Sense: Turning Left");
              #endif
							turnLeft(MAX_MOT_TURNING_SPEED_LEFT, MAX_MOT_TURNING_SPEED_LEFT_COMPENSATE);
							delay(MOT_TURNING_DELAY);
              stopMotors(500);
							break;
						default:
							stopMotors(MOT_STOP_DELAY);
							break;
					}
				}
			}			
		}
		
		#ifdef DEBUG
			Serial.println("");
			Serial.println("Distance Right:" + String(IR_SENSOR_ARRAY[0]) );
			Serial.println("Distance Center:" + String(IR_SENSOR_ARRAY[1]) );
			Serial.println("Distance Left:" + String(IR_SENSOR_ARRAY[2]) );
		#endif

		tempT = millis();
 	}		
}
