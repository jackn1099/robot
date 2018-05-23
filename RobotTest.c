#include "Robot.h"
#include "stdio.h"
void main()
{
	robotInit(0x60,1,2,0,0);
          // Move forward at speed 150 for 1 second.
         //Spin left at speed 200 for 0.5 seconds.
         //Repeat the same movement 3 times below...
	
	backward(200,1000);
	forward(200,1000);
	left(200,2000);
	right(200,2000);


}

