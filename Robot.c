#include "Robot.h"
#include "MotorHat.h"
#include <math.h>
#include <bcm2835.h>
extern void robotInit(unsigned int address, int left_id, int right_id, int left_trim, int right_trim)
{
	init1(0x60);
	dcInit();
	hatInit(0x60,1600);
	list[0] = getMotor(1);
	list[1] = getMotor(2);
	run(RELEASE);
}

extern void leftSpeed(int speed)
{	
	setSpeed(speed);
}

extern void rightSpeed(int speed)
{
	setSpeed(speed);

}
extern void stop()
{
	run(RELEASE);

}

extern void forward(int speed, int seconds)
{
	leftSpeed(speed);
	rightSpeed(speed);
	run(FORWARD);
	if(seconds > 0)
	{
		bcm2835_delay(seconds);
		stop();
	}
	

}

extern void backward(int speed, int seconds)
{
	leftSpeed(speed);
	rightSpeed(speed);
	run(BACKWARD);
	if(seconds > 0)
	{
		bcm2835_delay(seconds);	
		stop();
	}
}

extern void right(int speed, int seconds)
{
	leftSpeed(speed);
	rightSpeed(speed);
	run(RIGHT);
	if(seconds > 0)
	{
		bcm2835_delay(seconds);
		stop();
	}
}

extern void left(int speed, int seconds)
{
	leftSpeed(speed);
	rightSpeed(speed);
	run(LEFT);
	if(seconds > 0)
	{
		bcm2835_delay(seconds);
		stop();
	}
}


