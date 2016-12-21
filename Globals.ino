// comment out to disable debug
//#define DEBUG

// comment out to disable feedback leds on board
// #define DEBUGLED

#define START_AUTO_MODE 'a'
#define START_TEST_MODE 'b'
#define POWERDOWN_COMMAND 'c'
#define POWERUP_COMMAND 'd'
#define MOD_A_SERVO_MOVE 'e'
#define CONTINUE 'f'
#define START_LOW_POWER_MODE 'g'
#define START_CAMERA_MODE 'h'
#define START_TALKING_MODE 'i'
#define WAIT_COMMAND 'j'
#define MOD_D_SERVO_MOVE 'k'
#define START_ARDUINO_COMMAND 'l'
#define CONTINUE_AUTO 'm'

#define COLOR_RED 'z'
#define COLOR_GREEN 'y'
#define COLOR_BLUE 'x'
#define COLOR_PINK 'w'
#define NUM_PIXELS 1

// constants
// pin configurations
// IR Distance Sensors from L to R
const uint8_t NUM_OF_DIST_SENSORS = 3;
const uint8_t PIN_DIST_SENS_R = A0;
const uint8_t PIN_DIST_SENS_M = A1;
const uint8_t PIN_DIST_SENS_L = A2;

// leds
const uint8_t PIN_TURN_LEFT_INDICATOR = A15;
const uint8_t PIN_MOVE_STRAIGHT_INDICATOR = A12;
const uint8_t PIN_TURN_RIGHT_INDICATOR = A9;
// 48 for on board
// 40 for antenna
const uint8_t PIN_MODE_INDICATOR = 40;

// power control
const uint8_t PIN_POWER_CONTROL = 35;

// Front Motor Left
const uint8_t PIN_SPEED_MOT_LEFT_FRONT = 4;
const uint8_t PIN_DIR_MOT_LEFT_FRONT = 27;

// Front Motor Right
const uint8_t PIN_SPEED_MOT_RIGHT_FRONT = 2;
const uint8_t PIN_DIR_MOT_RIGHT_FRONT = 23;

// Back Motor Left
const uint8_t PIN_SPEED_MOT_LEFT_BACK = 5;
const uint8_t PIN_DIR_MOT_LEFT_BACK = 29;

// Back Motor Right
const uint8_t PIN_SPEED_MOT_RIGHT_BACK = 3;
const uint8_t PIN_DIR_MOT_RIGHT_BACK = 25;

// Servo for Arms
const uint8_t PIN_SERVO_RIGHT = 39;
const uint8_t PIN_SERVO_LEFT = 37;

// Encoder pins
// left front wheel encoder
const uint8_t PIN_ENCODER_L_F_A = 18;
const uint8_t PIN_ENCODER_L_F_B = 28;
// left back wheel encoder
const uint8_t PIN_ENCODER_L_B_A = 19;
const uint8_t PIN_ENCODER_L_B_B = 26;
// right front wheel encoder
const uint8_t PIN_ENCODER_R_F_A = 21;
const uint8_t PIN_ENCODER_R_F_B = 22;
// right back wheel encoder
const uint8_t PIN_ENCODER_R_B_A = 20;
const uint8_t PIN_ENCODER_R_B_B = 24;

// motor directions
const boolean FWD_MOT_LEFT = true;
const boolean FWD_MOT_RIGHT = true;

// motor speeds
const uint8_t MAX_MOT_SPEED =50;
const uint8_t MAX_MOT_SPEED_TEST = 50;
const uint8_t MAX_MOT_TURNING_SPEED_LEFT = 210;
const uint8_t MAX_MOT_TURNING_SPEED_LEFT_COMPENSATE = 170;
const uint8_t MAX_MOT_TURNING_SPEED_RIGHT = 210;
const uint16_t MAX_SAMPLING_RATE_IR = 500;

// for servo angle settings
const uint16_t MAX_ANGLE_SERVO = 180;
const uint16_t MIN_ANGLE_SERVO = 10;
const uint16_t INITIAL_SERVO_POS = 40;

// test duration
const uint32_t MAX_TEST_TIME = 3000;
const unsigned long MOT_STOP_DELAY = 500;
const unsigned long MOT_TURNING_DELAY = 200;

// sensing max distance
const uint8_t MAX_DIST_CENTER = 40;
const uint8_t MAX_DIST_RIGHT = 40;
const uint8_t MAX_DIST_LEFT = 40;

char inputChar = 'x';
boolean charComplete = true;

const uint8_t FORWARDED = 0;
const uint8_t TURNED_LEFT = 1;
const uint8_t TURNED_RIGHT = 2;
const uint8_t NO_DATA = 3;
uint8_t lastMove = NO_DATA;

uint8_t INPUT_PIN_ARRAY[] = {
	PIN_DIST_SENS_R, PIN_DIST_SENS_M, PIN_DIST_SENS_L
};

uint8_t OUTPUT_PIN_ARRAY[] = {
	PIN_SPEED_MOT_LEFT_FRONT, PIN_DIR_MOT_LEFT_FRONT,
	PIN_SPEED_MOT_RIGHT_FRONT, PIN_DIR_MOT_RIGHT_FRONT,
	PIN_SPEED_MOT_LEFT_BACK, PIN_DIR_MOT_LEFT_BACK,
	PIN_SPEED_MOT_RIGHT_BACK, PIN_DIR_MOT_RIGHT_BACK,
	PIN_TURN_LEFT_INDICATOR, PIN_TURN_RIGHT_INDICATOR, PIN_MOVE_STRAIGHT_INDICATOR,
	PIN_POWER_CONTROL
};

uint8_t IR_SENSOR_ARRAY[3] = {
	0, 0, 0
};

uint32_t readValues=0;
