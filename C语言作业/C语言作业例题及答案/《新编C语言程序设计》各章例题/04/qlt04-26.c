#include <math.h>
#include <stdio.h>
void main()
{  float a,b,c,disc,x1,x2,p,q;
   scanf("a=%f,b=%f,c=%f",&a,&b,&c);
   disc=b*b-4*a*c; p=-b/(2*a);
   q=sqrt(disc)/(2*a); //disc�Ƿ��ܱ�֤���ڵ���0���������ĳ���������½�
   x1=p+q;x2=p-q;
   printf("\nx1=%5.2f\nx2=%5.2f\n",x1,x2);
}
