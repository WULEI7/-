#include <stdio.h>
void main()
{  unsigned a,b,c;
   int n;
   printf("please enter a & n:\n");
   scanf("a=%o,n=%d",&a,&n);
   b=a<<(32-n);        //Ҫѭ������nλ����Ϊ��b=a>> (32-n);
   printf("a:%o\nb:%o\n",a,b);
   c=a>>n;             //Ҫѭ������nλ����Ϊ��c=a<<n;
   printf("c:%o\n",c);
   c=c|b;
   printf("c|b:%o\n",c);
}
