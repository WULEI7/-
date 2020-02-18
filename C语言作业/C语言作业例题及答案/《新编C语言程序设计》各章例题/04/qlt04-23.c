#include <math.h>
#include <stdio.h>
void main()
{  float a,b,c,p,area;
   printf("Input a,b,c: ");
   scanf("%f,%f,%f",&a,&b,&c);
   p=1.0/2*(a+b+c);  //»ò p=(a+b+c)/2;
   area=sqrt(p*(p-a)*(p-b)*(p-c));
   printf("a=%7.2f,b=%7.2f,c=%7.2f,p=%7.2f\n",a,b,c,p);
   printf("area=%7.2f\n",area);
}
