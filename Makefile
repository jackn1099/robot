all:
	gcc -c Servo.c
	gcc -c MotorHat.c
	gcc -c Robot.c
	gcc Servo.o MotorHat.o Robot.o RobotTest.o -L /home/pi/Downloads/bcm2835-1.55/src -lbcm2835 -lm -o RobotTest
clean:
	rm Servo.o
	rm MotorHat.o
	rm Robot.o
