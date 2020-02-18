#include <stdio.h>
main(){
   char a='a',b='b';int p,c,d;
   p=a;
   p=(p<<8)|b;
   d=p&0xff;
   c=(p&0xff00)>>8;
   printf("a=%d\nb=%d\nc=%d\nd=%d\n",a,b,c,d);
}
