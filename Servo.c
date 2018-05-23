//compile with "gcc -c Servo.c"
#include <bcm2835.h>
#include "Servo.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>	//to use floor

extern void init1(unsigned int address) //Servo_Driver.py init
{
	init2(address);
	setAllPWM(0,0);
	write8( __MODE2,__OUTDRV);
	write8(__MODE1,__ALLCALL);
	bcm2835_delay(5);
	int model = readU8(__MODE1);
	write8(__MODE1, model);
	bcm2835_delay(5);	
}//init1



extern int init2(unsigned int slave_address)  //Adafruit_I2C.py init 
{
	if (!bcm2835_init())
    	{
     		printf("bcm2835_init failed. Are you running as root??\n");
      		return 1;
    	}//if bcm_init
	
	if (!bcm2835_i2c_begin())
    	{
		printf("bcm2835_i2c_begin failed. Are you running as root??\n");
		return 1;
	}//if i2c_begin

	bcm2835_i2c_setSlaveAddress(slave_address); //set HAT address to 0x40
	return 0;
}


extern void setPWMFreq(int freq) //sets the PWM frequency
{
	prescaleval = 25000000.0;
	prescaleval /=4096.0;
	prescaleval /= freq;
	prescaleval -= 1.0;
	prescale = prescaleval +0.5;
	oldmode = readU8(__MODE1);
	newmode = (oldmode & 0x7F) | 0x10;
	write8(__MODE1, newmode);
	int prescale1 = prescale;
	write8(__PRESCALE, prescale1 );
	write8(__MODE1, oldmode);
	bcm2835_delay(5);
	write8(__MODE1, oldmode | 0x80);
}


extern void setPWM(int channel, int on, int off) //set a single PWM channel
{
        write8(__LED0_ON_L+4*channel, on & 0xFF);
        write8(__LED0_ON_H+4*channel, on >> 8);
        write8(__LED0_OFF_L+4*channel, off & 0xFF);
        write8(__LED0_OFF_H+4*channel, off >> 8);
  
}


extern void setAllPWM(int on, int off) //set all PWM channels
{
	write8(__ALL_LED_ON_L, on & 0xFF);
	write8(__ALL_LED_ON_H, on >> 8);
	write8(__ALL_LED_OFF_L, off & 0xFF);
	write8(__ALL_LED_OFF_H, off >> 8);	
}



extern void write8(unsigned char reg, unsigned char value) //writes 8-bit value to register/address
{
	buffer[0] = reg;
	buffer[1] = value;
	bcm2835_i2c_write (buffer, 2);
}


extern unsigned int readU8(unsigned char reg) //read an unsigned byte from the I2C device
{
	unsigned int result;
	buffer[0] = reg;
	result = bcm2835_i2c_read(buffer, 1); //char *buf, uint32_t len
	return result;
//buffer or buffer[1]

}//readU8()

