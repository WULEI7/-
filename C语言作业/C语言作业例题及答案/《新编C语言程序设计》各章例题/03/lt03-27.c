#include <stdio.h>
void main()
{  long a=23456,b=56789,c;
   printf("%8ld\n",a);
   printf("%2c%6ld\n",'+',b);
   printf("%8s\n","--------");
   c=a+b;
   printf("%8ld\n",c);
}

