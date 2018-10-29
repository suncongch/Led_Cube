#include "config.h"

void delay5us(void)   //误差 -0.026765046296us STC 1T 22.1184Mhz
{
    unsigned char a,b;
    for(b=7;b>0;b--)
        for(a=2;a>0;a--);
}

void delay(uint i)

{                                                                                                     

         while (i--){
		 delay5us();}//12t的mcu 注释这个延时即可
}


