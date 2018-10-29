#include "REG52.H"
#include "intrins.h"
#include "config.h"
#include "math.h"
#include "delay.h"


/*From now on,the function below is to display the flash.*/


void flash_1()

{

 

         clear(0);

         type(1,0);

         delay(60000);

         type(2,0);

         delay(60000);

         type(3,0);

         delay(60000);

         type(4,0);

         delay(60000);

         delay(60000);

         clear(0);

         rolldisplay(30000);

         type(0,7);

         delay(60000);

         trailler(6000);

         delay(60000);

}

void flash_2()

{

         uchar i;

         for (i=129;i>0;i--)

         {

                   cirp(i-2,0,1);

                   delay(8000);

                   cirp(i-1,0,0);

         }

         delay(8000);     

         for (i=0;i<136;i++)

         {

                   cirp(i,1,1);

                   delay(8000);

                   cirp(i-8,1,0);

         }

         delay(8000);

                  for (i=129;i>0;i--)

         {

                   cirp(i-2,0,1);

                   delay(8000);

         }

         delay(8000);

                   for (i=0;i<128;i++)

         {

                   cirp(i-8,1,0);

                   delay(8000);

         }

         delay(60000);  

}

void flash_3()

{

         char i;

         for (i=0;i<8;i++)

         {

                   box_apeak_xy(0,i,0,7,i,7,1,1);

                   delay(20000);

                   if (i<7)

                   box_apeak_xy(0,i,0,7,i,7,1,0);

         }

         for (i=7;i>=0;i--)

         {

                   box_apeak_xy(0,i,0,7,i,7,1,1);

                   delay(20000);

                   if (i>0)

                   box_apeak_xy(0,i,0,7,i,7,1,0);

         }

         for (i=0;i<8;i++)

         {

                   box_apeak_xy(0,i,0,7,i,7,1,1);

                   delay(20000);

                   if (i<7)

                   box_apeak_xy(0,i,0,7,i,7,1,0);

         }

}

void flash_4()

{

         char i,j,an[8];

         for (j=7;j<15;j++)

                   an[j-7]=j;

         for (i=0;i<=16;i++)

         {

                   for (j=0;j<8;j++)

                   {

                            if ((an[j]<8)&(an[j]>=0))

                            line(0,an[j],j,7,an[j],j,1);

                   }

                   for (j=0;j<8;j++)

                   {

                            if (((an[j]+1)<8)&(an[j]>=0))

                            line(0,an[j]+1,j,7,an[j]+1,j,0);

                   }

                   for (j=0;j<8;j++)

                   {

                            if (an[j]>0)

                            an[j]--;

                   }

                   delay(15000);

         }

         for (j=0;j<8;j++)

                   an[j]=1-j;

         for (i=0;i<=16;i++)

         {

                   for (j=0;j<8;j++)

                   {

                            if ((an[j]<8)&(an[j]>=0))

                            line(0,an[j],j,7,an[j],j,1);

                   }

                   for (j=0;j<8;j++)

                   {

                            if (((an[j]-1)<7)&(an[j]>0))

                            line(0,an[j]-1,j,7,an[j]-1,j,0);

                   }

                   for (j=0;j<8;j++)

                   {

                            if (an[j]<7)

                            an[j]++;

                   }

                   delay(15000);

         }

}

void flash_5()

{

         uint a=15000;//a=delay

         char i=8,j,an[4];

         //1

         for (j=7;j<11;j++)

                   an[j-7]=j;

         while(i--)

         {

                   for (j=0;j<4;j++)

                   {

                            if (an[j]<8)

                            box_apeak_xy(j,an[j],j,7-j,an[j],7-j,0,1);

                            if (an[j]<7)

                            box_apeak_xy(j,an[j]+1,j,7-j,an[j]+1,7-j,0,0);

                   }

                   for (j=0;j<4;j++)

                   {

                            if (an[j]>3)

                            an[j]--;

                   }

                   delay(a);

         }

         //2

         i=3;

         for (j=0;j<4;j++)

         an[j]=5-j;

         while(i--)

         {

                   for (j=1;j<4;j++)

                   {

                            if (an[j]<4)

                            box_apeak_xy(j,an[j],j,7-j,an[j],7-j,0,1);

                            if (an[j]<3)

                            box_apeak_xy(j,an[j]+1,j,7-j,an[j]+1,7-j,0,0);

                   }

                   for (j=0;j<4;j++)

                   {

                            if (an[j]>0)

                            an[j]--;

                   }

                   delay(a);

         }

         //3

         i=3;

         for (j=1;j<4;j++)

         an[j]=4-j;

         while(i--)

         {

                   for (j=1;j<4;j++)

                   {

                            if (an[j]>=0)

                            box_apeak_xy(j,an[j],j,7-j,an[j],7-j,0,1);

                            if (an[j]>0)

                            box_apeak_xy(j,an[j]-1,j,7-j,an[j]-1,7-j,0,0);

                   }

                   for (j=1;j<4;j++)

                   {

                            if (an[j]<3)

                            an[j]++;

                   }

                   delay(a);

         }

 

         //4

         i=3;

         for (j=0;j<4;j++)

         an[j]=j+1;

         while(i--)

         {

                   for (j=1;j<4;j++)

                   {

                            if (an[j]>3)

                            box_apeak_xy(j,an[j],j,7-j,an[j],7-j,0,1);

                            if (an[j]>3)

                            box_apeak_xy(j,an[j]-1,j,7-j,an[j]-1,7-j,0,0);

                   }

                   for (j=0;j<4;j++)

                            an[j]++;

                   delay(a);

         }

         //5

         i=3;

         for (j=3;j<6;j++)

                   an[j-2]=j;

         while(i--)

         {

                   for (j=1;j<4;j++)

                   {

                            box_apeak_xy(j,an[j],j,7-j,an[j],7-j,0,1);

                            box_apeak_xy(j,an[j]+1,j,7-j,an[j]+1,7-j,0,0);

                   }

                   for (j=0;j<4;j++)

                   {

                            if (an[j]>3)

                            an[j]--;

                   }

                   delay(a);

         }

         //6

         i=3;

         for (j=0;j<4;j++)

         an[j]=5-j;

         while(i--)

         {

                   for (j=1;j<4;j++)

                   {

                            if (an[j]<4)

                            box_apeak_xy(j,an[j],j,7-j,an[j],7-j,0,1);

                            if (an[j]<3)

                            box_apeak_xy(j,an[j]+1,j,7-j,an[j]+1,7-j,0,0);

                   }

                   for (j=0;j<4;j++)

                   {

                            if (an[j]>0)

                            an[j]--;

                   }

                   delay(a);

         }

         //7

         i=3;

         for (j=0;j<4;j++)

         an[j]=3-j;

         an[0]=2;

         while(i--)

         {

                   for (j=0;j<3;j++)

                   {

                            if (an[j]>=0)

                                     box_apeak_xy(j,an[j],j,7-j,an[j],7-j,0,1);

                            if (an[j]>=0)

                                     box_apeak_xy(j,an[j]+1,j,7-j,an[j]+1,7-j,0,0);

                   }

                   for (j=0;j<4;j++)

                   {

                            if (j<5-i)

                            an[j]--;

                   }

                   delay(a);

         }

         //8

         i=10;

         for (j=0;j<4;j++)

                   an[j]=j-2;

         while(i--)

         {

                   for (j=0;j<4;j++)

                   {

                            if (an[j]>=0)

                            box_apeak_xy(j,an[j],j,7-j,an[j],7-j,0,1);

                            if (an[j]>=0)

                            box_apeak_xy(j,an[j]-1,j,7-j,an[j]-1,7-j,0,0);

                   }

                   for (j=0;j<4;j++)

                   {

                            if (an[j]<7)

                            an[j]++;

                   }

                   delay(a);

         }

}

void flash_6()

{

      uchar i,j,k,z;

      roll_apeak_yz(1,10000);

      roll_apeak_yz(2,10000);

      roll_apeak_yz(3,10000);

      roll_apeak_yz(0,10000);

      roll_apeak_yz(1,10000);

      roll_apeak_yz(2,10000);

      roll_apeak_yz(3,10000);

      for (i=0;i<3;i++)

               {

                         for (j=0;j<8;j++)

                         {

                                  for (k=0;k<8;k++)

                                  {

                                           if ((table_3p[i][j]>>k)&1)

                                           {

                                                     for (z=1;z<8;z++)

                                                              {

                                                                       point (j,7-k,z,1);

                                                                       if (z-1)

                                                                       point (j,7-k,z-1,0);

                                                                       delay(5000);

                                                              }

                                           }

                                  }

                         }

                         trans(7,15000);

               }

}

void flash_7()

{

      uchar i;

      uint a=3000;

      roll_apeak_yz(0,10000);

      roll_apeak_yz(1,10000);

      roll_apeak_yz(2,10000);

      roll_apeak_yz(3,10000);

      roll_apeak_yz(0,10000);

      roll_apeak_yz(1,10000);

      roll_apeak_yz(2,10000);

      roll_apeak_yz(3,10000);

      roll_apeak_yz(0,10000);

      roll_apeak_yz(1,10000);

      roll_apeak_yz(2,10000);

      roll_apeak_xy(0,10000);

      roll_apeak_xy(1,10000);

      roll_apeak_xy(2,10000);

      roll_apeak_xy(3,10000);

      roll_apeak_xy(0,10000);

      roll_apeak_xy(1,10000);

      roll_apeak_xy(2,10000);

      roll_apeak_xy(3,10000);

      for (i=0;i<8;i++)

      {

               box_apeak_xy (0,i,0,7-i,i,7,1,1);

               delay(a);

      }

      delay(30000);

      roll_3_xy(0,a);

      delay(30000);

      roll_3_xy(1,a);

      delay(30000);

      roll_3_xy(2,a);

      delay(30000);

      roll_3_xy(3,a);

      delay(30000);

      roll_3_xy(0,a);

      delay(30000);

      roll_3_xy(1,a);

      delay(30000);

      roll_3_xy(2,a);

      delay(30000);

      roll_3_xy(3,a);

      for (i=7;i>0;i--)

      {

               box_apeak_xy(i,0,0,i,7,7,1,0);

               delay(a);

      }

}

void flash_8()

{

      uchar i;

      for (i=5;i<8;i++)

      {

               tranoutchar(i,10000);

               delay(60000);

               delay(60000);

      }

}

void flash_9()

{

      char i;

      uchar j,an[8],x,y,t,x1,y1;

      for (i=0;i<8;i++)

      {

               box_apeak_xy (i,0,0,i,7,7,1,1);

               if (i)

               box_apeak_xy (i-1,0,0,i-1,7,7,1,0);

               delay(10000);

      }

      roll_apeak_xy(3,10000);

      roll_apeak_xy(0,10000);

      roll_apeak_xy(1,10000);

      for (i=0;i<7;i++)

      {

               line(6-i,6-i,0,6-i,6-i,7,1);

               line(i,7,0,i,7,7,0);

               delay(10000);

      }

      for (i=0;i<8;i++)

               an[i]=14;

      for (i=0;i<85;i++)

      {

               clear(0);

               for (j=0;j<8;j++)

               {

                         t=an[j]%28;

                         x=dat2[t]>>5;

                         y=(dat2[t]>>2)&0x07;

                         t=(an[j]-14)%28;

                         x1=dat2[t]>>5;

                         y1=(dat2[t]>>2)&0x07;

                         line(x,y,j,x1,y1,j,1);

               }

               for (j=0;j<8;j++)

               {

               if ((i>j)&(j>i-71))

               an[j]++;

               } 

               delay(5000);

      }

      for (i=0;i<85;i++)

      {

               clear(0);

               for (j=0;j<8;j++)

               {

                         t=an[j]%28;

                         x=dat2[t]>>5;

                         y=(dat2[t]>>2)&0x07;

                         t=(an[j]-14)%28;

                         x1=dat2[t]>>5;

                         y1=(dat2[t]>>2)&0x07;

                         line(x,y,j,x1,y1,j,1);

               }

               for (j=0;j<8;j++)

               {

               if ((i>j)&(j>i-71))

               an[j]--;

               } 

               delay(5000);

      }

      for (i=0;i<29;i++)

      {

               clear(0);



               t=an[0]%28;

               x=dat2[t]>>5;

               y=(dat2[t]>>2)&0x07;

               t=(an[0]-14)%28;

               x1=dat2[t]>>5;

               y1=(dat2[t]>>2)&0x07;

               box_apeak_xy(x,y,0,x1,y1,7,0,1);

               box_apeak_xy(x,y,1,x1,y1,6,0,1);

               an[0]++; 

               delay(5000);

      }

      for (i=0;i<16;i++)

      {

               clear(0);



               t=an[0]%28;

               x=dat2[t]>>5;

               y=(dat2[t]>>2)&0x07;

               t=(an[0]-14)%28;

               x1=dat2[t]>>5;

               y1=(dat2[t]>>2)&0x07;

               box_apeak_xy(x,y,0,x1,y1,7,1,1);

               an[0]--; 

               delay(5000);

      }

      for (i=0;i<8;i++)

      {

               line(i,i,0,0,0,i,0);

               delay(5000);

      }

      for (i=1;i<7;i++)

      {

               line(i,i,7,7,7,i,0);

               delay(5000);

      }

      for (i=1;i<8;i++)

      {

               clear(0);

               box(7,7,7,7-i,7-i,7-i,0,1);

               delay(10000);

      }

      for (i=1;i<7;i++)

      {

               clear(0);

               box(0,0,0,7-i,7-i,7-i,0,1);

               delay(10000);

      }

      for (i=1;i<8;i++)

      {

               clear(0);

               box(0,0,0,i,i,i,0,1);

               delay(10000);

      }

      for (i=1;i<7;i++)

      {

               clear(0);

               box(7,0,0,i,7-i,7-i,0,1);

               delay(10000);

      }

      for (i=1;i<8;i++)

      {

               box(7,0,0,7-i,i,i,1,1);

               delay(10000);

      }

      for (i=1;i<7;i++)

      {

               clear(0);

               box(0,7,7,7-i,i,i,1,1);

               delay(10000);

      }

}

void flash_10()

{

      uchar i,j,an[4],x,y,t;

      for (i=1;i<7;i++)

      {

               

               clear(0);

               box(0,6,6,1,7,7,1,1);

               box(i,6,6-i,i+1,7,7-i,1,1);

               box(i,6,6,i+1,7,7,1,1);

               box(0,6,6-i,1,7,7-i,1,1);

               box(0,6-i,6,1,7-i,7,1,1);

               box(i,6-i,6-i,i+1,7-i,7-i,1,1);

               box(i,6-i,6,i+1,7-i,7,1,1);

               box(0,6-i,6-i,1,7-i,7-i,1,1);

               delay(30000);

      }

      for (i=0;i<4;i++)

      {

               an[i]=6*i;

      }

      for (i=0;i<35;i++)

      {

               clear(0);

               for(j=0;j<4;j++)

               {

                         t=an[j]%24;

                         x=dat3[t]>>4;

                         y=dat3[t]&0x0f;

                         box(x,y,0,x+1,y+1,1,1,1);

                         box(x,y,6,x+1,y+1,7,1,1);

               }

               for (j=0;j<4;j++)

               an[j]++; 

               delay(10000);

      }

      for (i=0;i<35;i++)

      {

               clear(0);

               for(j=0;j<4;j++)

               {

                         t=an[j]%24;

                         x=dat3[t]>>4;

                         y=dat3[t]&0x0f;

                         box(x,y,0,x+1,y+1,1,1,1);

                         box(x,y,6,x+1,y+1,7,1,1);

               }

               for (j=0;j<4;j++)

               an[j]--; 

               delay(10000);

      }

      for (i=0;i<35;i++)

      {

               clear(0);

               for(j=0;j<4;j++)

               {

                         t=an[j]%24;

                         x=dat3[t]>>4;

                         y=dat3[t]&0x0f;

                         box(x,0,y,x+1,1,y+1,1,1);

                         box(x,6,y,x+1,7,y+1,1,1);

               }

               for (j=0;j<4;j++)

               an[j]++; 

               delay(10000);

      }

      for (i=0;i<36;i++)

      {

               clear(0);

               for(j=0;j<4;j++)

               {

                         t=an[j]%24;

                         x=dat3[t]>>4;

                         y=dat3[t]&0x0f;

                         box(x,0,y,x+1,1,y+1,1,1);

                         box(x,6,y,x+1,7,y+1,1,1);

               }

               for (j=0;j<4;j++)

               an[j]--; 

               delay(10000);

      }

      for (i=6;i>0;i--)

      {

               

               clear(0);

               box(0,6,6,1,7,7,1,1);

               box(i,6,6-i,i+1,7,7-i,1,1);

               box(i,6,6,i+1,7,7,1,1);

               box(0,6,6-i,1,7,7-i,1,1);

               box(0,6-i,6,1,7-i,7,1,1);

               box(i,6-i,6-i,i+1,7-i,7-i,1,1);

               box(i,6-i,6,i+1,7-i,7,1,1);

               box(0,6-i,6-i,1,7-i,7-i,1,1);

               delay(3000);

      }

}

void flash_11()

{

      uchar i,j,t,x,y;

      uchar code daa[13]={0,1,2,0x23,5,6,7,6,5,0x23,2,1,0};

      for (j=0;j<5;j++)

      {

               for (i=0;i<13;i++)

               {

                         if (daa[i]>>4)

                         {

                                  t=daa[i]&0x0f;

                                  line (0,0,t+1,0,7,t+1,1);

                         }

                         else 

                                  t=daa[i];

                         line (0,0,t,0,7,t,1);

                         transss();

                         delay(10000);

               }

      }

      for (j=1;j<8;j++)

      {

               if (j>3)

                         t=4;

               else

                         t=j;

               for (i=0;i<24;i+=j)

               {

                         x=dat3[i]>>4;

                         y=dat3[i]&0x0f;

                         box_apeak_xy(0,x,y,0,x+1,y+1,1,1);

                         transss();

                         delay(10000);

               }

      }

      for (j=1;j<8;j++)

      {

               if (j>3)

                         t=4;

               else

                         t=j;

               for (i=0;i<24;i+=j)

               {

                         x=dat3[i]>>4;

                         y=dat3[i]&0x0f;

                         point (0,x,y,1);

                         transss();

                         delay(10000);

               }

      }

}

void flash(int x)
{
	switch(x){
		case 1:flash_1();break;
		case 2:flash_2();break;
		case 3:flash_3();break;
		case 4:flash_4();break;
		case 5:flash_5();break;
		case 6:flash_6();break;
		case 7:flash_7();break;
		case 8:flash_8();break;
		case 9:flash_9();break;
		case 10:flash_10();break;
		case 11:flash_11();break;
	}
}

