#include "REG52.H"
#include "intrins.h"
#include "config.h"
#include "delay.h"
#include "flash.h"
#include "config.h"


/*To judge the num bit*/

uchar judgebit(uchar num,uchar b)

{

         char n;

         num=num&(1<<b);

         if (num)

         n=1;

         else

         n=0;

         return n;

}

/*To figure out the round number*/

uchar abs(uchar a)

{

         uchar b;

         b=a/10;

         a=a-b*10;

         if (a>=5)

         b++;

         return b;

}

/*To figure out the absolute value*/

uchar abss(char a)

{

         if (a<0)

         a=-a;

         return a;

}

/*The function can comparat the character.

And remove the big one to the back.*/

void max(uchar *a,uchar *b)

{

   uchar t;

   if ((*a)>(*b))

   {

                   t=(*a);

                   (*a)=(*b);

                   (*b)=t;   

   }

}

/*The function is to figure out the max number and return it.*/

uchar maxt(uchar a,uchar b,uchar c)

{

         if (a<b)

         a=b;

         if (a<c)

         a=c;

         return a;

}

void clear(char le)

{

         uchar i,j;

         for (j=0;j<8;j++)

         {

                   for (i=0;i<8;i++)

                   display[j][i]=le;

         }

}

void trailler(uint speed)

{

         char i,j;

         for (i=6;i>=-3;i--)

         {

                   if (i>=0)

                   {

                            for (j=0;j<8;j++)

                            display[j][i]=display[j][i+1];

                   }

                   if (i<4)

                   {

                            for (j=0;j<8;j++)

                            display[j][i+4]=0;

                   }

                   delay(speed);

         }

}

void point(uchar x,uchar y,uchar z,uchar le)

{

         uchar ch1,ch0;

         ch1=1<<x;

         ch0=~ch1;

         if (le) 

         display[z][y]=display[z][y]|ch1;

         else 

         display[z][y]=display[z][y]&ch0;

}

void type(uchar cha,uchar y)

{        

         uchar xx;

         for (xx=0;xx<8;xx++)

         {

         display[xx][y]=table_cha[cha][xx];

         }

}

/*The first variable is the distance from the midpoint.

The second is the layer.

the third is the flash speed of the time between each two point.

The forth is the enable io,it controls weather draw or claen.*/

void cirp(char cpp,uchar dir,uchar le)

{

         uchar a,b,c,cp;

         if ((cpp<128)&(cpp>=0))

         {

                   if (dir)

                   cp=127-cpp;

                   else 

                   cp=cpp; 

                   a=(dat[cp]>>5)&0x07;

                   b=(dat[cp]>>2)&0x07;

                   c=dat[cp]&0x03;

                   if (cpp>63)

                   c=7-c;

                   point (a,b,c,le);

         }

}

void line(uchar x1,uchar y1,uchar z1,uchar x2,uchar y2,uchar z2,uchar le)

{

         char t,a,b,c,a1,b1,c1,i;

         a1=x2-x1;

         b1=y2-y1;

         c1=z2-z1;

         t=maxt(abss(a1),abss(b1),abss(c1));

         a=x1*10;

         b=y1*10;

         c=z1*10;

         a1=a1*10/t;

         b1=b1*10/t;

         c1=c1*10/t;

         for (i=0;i<t;i++)

         {

                   point(abs(a),abs(b),abs(c),le);

                   a+=a1;

                   b+=b1;

                   c+=c1;

         }

         point(x2,y2,z2,le);

}

void box(uchar x1,uchar y1,uchar z1,uchar x2,uchar y2,uchar z2,uchar fill,uchar le)

{

         uchar i,j,t=0;

         max(&x1,&x2);

         max(&y1,&y2);

         max(&z1,&z2);

         for (i=x1;i<=x2;i++)

                   t|=1<<i;

         if (!le)

                   t=~t;

         if (fill)

         {

                   if (le)

                   {

                            for (i=z1;i<=z2;i++)

                            {

                                     for (j=y1;j<=y2;j++)

                                               display[j][i]|=t;

                            }

                   }

                   else

                   {

                            for (i=z1;i<=z2;i++)

                            {

                                     for (j=y1;j<=y2;j++)

                                               display[j][i]&=t;

                            }

                   }

         }

         else

         {

                   if (le)

                   {

                            display[y1][z1]|=t;

                            display[y2][z1]|=t;

                            display[y1][z2]|=t;

                            display[y2][z2]|=t;

                   }

                   else

                   {

                           display[y1][z1]&=t;

                            display[y2][z1]&=t;

                            display[y1][z2]&=t;

                            display[y2][z2]&=t;

                   }

                   t=(0x01<<x1)|(0x01<<x2);

                   if (!le)

                            t=~t;

                   if (le)

                   {

                            for (j=z1;j<=z2;j+=(z2-z1))

                            {

                                     for (i=y1;i<=y2;i++)

                                               display[i][j]|=t;

                            }

                            for (j=y1;j<=y2;j+=(y2-y1))

                            {

                                     for (i=z1;i<=z2;i++)

                                               display[j][i]|=t;

                            }

                   }

                   else

                   {

                            for (j=z1;j<=z2;j+=(z2-z1))

                            {

                                     for (i=y1;i<=y2;i++)

                                     {

                                     display[i][j]&=t;

                                     }

                            }

                            for (j=y1;j<=y2;j+=(y2-y1))

                            {

                                     for (i=z1;i<=z2;i++)

                                     {

                                     display[j][i]&=t;

                                     }

                            }

                   }

         }

}

void box_apeak_xy(uchar x1,uchar y1,uchar z1,uchar x2,uchar y2,uchar z2,uchar fill,uchar le)

{

         uchar i;

         max(&z1,&z2);

         if (fill)

         {

                   for (i=z1;i<=z2;i++)

                   {

                            line (x1,y1,i,x2,y2,i,le);

                   } 

         } 

         else

         {

                   line (x1,y1,z1,x2,y2,z1,le);

                   line (x1,y1,z2,x2,y2,z2,le);

                   line (x2,y2,z1,x2,y2,z2,le);

                   line (x1,y1,z1,x1,y1,z2,le);

         }

}

void poke(uchar n,uchar x,uchar y)

{

         uchar i;

         for (i=0;i<8;i++)

         {

          point(x,y,i,judgebit(n,i));

         }

}

void boxtola(char i,uchar n)

{

         if ((i>=0)&(i<8))

         {

                   poke(n,0,7-i);

         }

         if ((i>=8)&(i<16))

         {

                   poke(n,i-8,0);

         }

         if ((i>=16)&(i<24))

         {

                   poke(n,7,i-16);

         }

 

}

void rolldisplay(uint speed)

{

         uchar j;

         char i,a;

         for (i=23;i>-40;i--)

         {

                   for (j=0;j<40;j++)

                   {

                            a=i+j;

                            if ((a>=0)&(a<24))

                            boxtola(a,table_id[j]);

                   }

                   delay(speed);

         }

}

void roll_apeak_yz(uchar n,uint speed)

{

         uchar i;

         switch(n)

         {

                   case 1:

                            for (i=0;i<7;i++)

                            {

                                     display[i][7]=0;

                                     display[7][6-i]=255;

                                     delay(speed);

                            };

                            break;

                   case 2:

                            for (i=0;i<7;i++)

                            {

                                     display[7][7-i]=0;

                                     display[6-i][0]=255;

                                     delay(speed);

                            };

                            break;

                   case 3:

                            for (i=0;i<7;i++)

                            {

                                     display[7-i][0]=0;

                                     display[0][i+1]=255;

                                     delay(speed);

                            };

                            break;

                   case 0:

                            for (i=0;i<7;i++)

                            {

                                     display[0][i]=0;

                                     display[i+1][7]=255;

                                     delay(speed);

                            };

         }

}

void roll_apeak_xy(uchar n,uint speed)

{

         uchar i;

         switch(n)

         {

                   case 1:

                            for (i=0;i<7;i++)

                            {

                                     line(0,i,0,0,i,7,0);

                                     line(i+1,7,0,i+1,7,7,1);

                                     delay(speed);

                            };

                            break;

                   case 2:

                            for (i=0;i<7;i++)

                            {

                                     line(i,7,0,i,7,7,0);

                                     line(7,6-i,0,7,6-i,7,1);

                                     delay(speed);

                            };

                            break;

                   case 3:

                            for (i=0;i<7;i++)

                            {

                                     line(7,7-i,0,7,7-i,7,0);

                                     line(6-i,0,0,6-i,0,7,1);

                                     delay(speed);

                            };

                            break;

                   case 0:

                            for (i=0;i<7;i++)

                            {

                                     line(7-i,0,0,7-i,0,7,0);

                                     line(0,i+1,0,0,i+1,7,1);

                                     delay(speed);

                            };

         }

}

void roll_3_xy(uchar n,uint speed)

{

         uchar i;

         switch(n)

         {

                   case 1:

                            for (i=0;i<8;i++)

                            {

                                     box_apeak_xy (0,i,0,7,7-i,7,1,1);

                                     delay(speed);

                                     if (i<7)

                                     box_apeak_xy (3,3,0,0,i,7,1,0);

                            };

                            break;

                   case 2:

                            for (i=0;i<8;i++)

                            {

                                      box_apeak_xy (7-i,0,0,i,7,7,1,1);

                                     delay(speed);

                                     if (i<7)

                                     box_apeak_xy (3,4,0,i,7,7,1,0);

                            };

                            break;

                   case 3:

                            for (i=0;i<8;i++)

                            {

                                     box_apeak_xy (0,i,0,7,7-i,7,1,1);

                                     delay(speed);

                                     if (i<7)

                                     box_apeak_xy (4,4,0,7,7-i,7,1,0);

                            };

                            break;

                   case 0:

                            for (i=0;i<8;i++)

                            {

                                     box_apeak_xy (7-i,0,0,i,7,7,1,1);

                                     delay(speed);

                                     if (i<7)

                                     box_apeak_xy (4,3,0,7-i,0,7,1,0);

                            };

         }

}

void trans(uchar z,uint speed)

{

         uchar i,j;

         for (j=0;j<8;j++)

         {

                   for (i=0;i<8;i++)

                   {

                            display[z][i]>>=1;

                   }

                   delay(speed);

         }

}

void tranoutchar(uchar c,uint speed)

{

         uchar i,j,k,a,i2=0;

         for (i=0;i<8;i++)

         {

                   if (i<7)

                   box_apeak_xy (i+1,0,0,i+1,7,7,1,1);

                   box_apeak_xy (i2,0,0,i2,7,7,1,0);

                   a=0;

                   i2=i+1;

                   for (j=0;j<=i;j++)

                   {

                            a=a|(1<<j);

                   }

                   for (k=0;k<8;k++)

                   {

                            display[k][3]|=table_cha[c][k]&a;

                            display[k][4]|=table_cha[c][k]&a;

                   }

                   delay(speed);

         }

}

void transss()

{

         uchar i,j;

         for (i=0;i<8;i++)

         {

                   for (j=0;j<8;j++)

                   display[i][j]<<=1;

         }

}

 

