#include <stdio.h>
main(){
   struct bits
   {  unsigned a:1;
      unsigned b:3;
      unsigned c:4;
   } bit,*pbit;
   bit.a=1;
   bit.b=7;
   bit.c=15;
   printf("%d,%d,%d\n",bit.a,bit.b,bit.c);
   pbit=&bit;
   pbit->a=0;
   pbit->b&=3;
   pbit->c|=1;
   printf("%d,%d,%d\n",pbit->a,pbit->b,pbit->c);
}
