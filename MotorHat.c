#include "MotorHat.h"
#include "Servo.h"
#include <math.h>
#include <bcm2835.h>
extern void dcInit()
{
	list[0].pwm = 8;
	list[0].in2 = 9;
	list[0].in1 = 10;
	list[1].pwm = 13;
	list[1].in2 = 12;
	list[1].in1 = 11;
	list[2].pwm = 2;
	list[2].in2 = 3;
	list[2].in1 = 4;
	list[3].pwm = 7;
	list[3].in2 = 6;
	list[3].in1 = 5;

}

extern void run(int command)
{
 	if(command == FORWARD)
	{
		setPin(list[0].in2,0);
		setPin(list[0].in1,1);
		setPin(list[1].in2,1);
		setPin(list[1].in1,0);
	}
	if(command == BACKWARD)
	{
		setPin(list[0].in1,0);
		setPin(list[0].in2,1);
		setPin(list[1].in1,1);
		setPin(list[1].in2,0);
	}
	if(command == RELEASE)
	{
		setPin(list[0].in1,0);
		setPin(list[0].in2,0);
		setPin(list[1].in1,0);
		setPin(list[1].in2,0);
	}
	if(command == LEFT)
	{
		setPin(list[0].in1,0);
		setPin(list[0].in2,1);
		setPin(list[1].in2,1);
		setPin(list[1].in1,0);
	}
	if(command == RIGHT)
	{

		setPin(list[0].in2,0);
		setPin(list[0].in1,1);
		setPin(list[1].in1,1);
		setPin(list[1].in2,0);
	}

}

extern void setSpeed(int speed)
{
	if(speed < 0)
	{
		speed =0;	
	}
	if(speed > 255)
	{
		speed = 255;
	}
	setPWM(list[0].pwm, 0, speed*16);
	setPWM(list[1].pwm, 0, speed*16); 
}

extern void hatInit(int addr, int freq)
{
	addr = 0x60;
	freq = 1200;
	init1(addr);
	setPWMFreq(freq);
	
}

extern void setPin(int pin, int value)
{
	if(value == 0)
	{
		setPWM(pin,0,4096);
	}
	if(value == 1)
	{
		setPWM(pin, 4096, 0);
	}
}
extern motor getMotor(int num)
{
	return list[num-1];

}



