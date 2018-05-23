//This library contains all the functions needed for the Motor Hat
#ifndef MOTOR
#define MOTOR

#define FORWARD 1
#define BACKWARD 2
#define BRAKE 3
#define RELEASE 4
#define LEFT 5
#define RIGHT 6
#define SINGLE 1
#define DOUBLE 2
#define INTERLEAVE 3
#define MICROSTEP 4 

typedef struct MOTOR{
	int pwm;
	int in1;
	int in2;
}motor;
	
motor list[4];

void dcInit();
void run(int command);
void setSpeed(int speed);

void hatInit(int addr, int freq);
void setPin(int pin, int value);
motor getMotor(int num);

#endif

