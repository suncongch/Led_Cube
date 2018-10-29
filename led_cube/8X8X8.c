#include "REG52.H"
#include "intrins.h"
#include "config.h"
#include "math.h"
#include "delay.h"
#include "flash.h"



void main()

{
		
	sinter();
	
	while(1){
		           
        // clear(0);

        /*play list*/

        //flash_1();

//		clear(2);
//		trailler(10);
		while(1){
			clear(0);
			tranoutchar(0,8000);
			delay(40000);
			tranoutchar(2,8000);
			delay(40000);
		}
//		trailler(10);
		

	}

}
