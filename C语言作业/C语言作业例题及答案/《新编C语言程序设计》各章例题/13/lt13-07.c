#include <stdio.h>
void main()
{  unsigned a,b,c;
   int n;
   printf("please enter a & n:\n");
   scanf("a=%o,n=%d",&a,&n);
   b=a<<(32-n);        //要循环左移n位，改为：b=a>> (32-n);
   printf("a:%o\nb:%o\n",a,b);
   c=a>>n;             //要循环左移n位，改为：c=a<<n;
   printf("c:%o\n",c);
   c=c|b;
   printf("c|b:%o\n",c);
}
