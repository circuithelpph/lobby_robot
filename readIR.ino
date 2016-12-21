// IR samples reading

void readSamples(uint8_t irSensor){
	//uint16_t value = 0;
	for (uint16_t x = 0; x < MAX_SAMPLING_RATE_IR; x++){
		readValues += analogRead(irSensor);
	}
}

uint16_t takeAverage(){
	readValues /= MAX_SAMPLING_RATE_IR;
	
	if (readValues < 30){
		readValues = 31;
	}
	
	uint16_t distance = 5461 / ((readValues-17) - 2);
	return distance;
}