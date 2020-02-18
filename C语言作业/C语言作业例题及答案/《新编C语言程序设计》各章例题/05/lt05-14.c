#include <stdio.h>
#include <math.h>
int main()
{
   float a,b,c,p,area;
   printf("Input a,b,c:");scanf("%f,%f,%f",&a,&b,&c);
   if((a+b>c)&&(b+c>a)&&(c+a>b))  // a,b,c组成三角形的条件
   {   
      p=(a+b+c)/2;
      area=sqrt(p*(p-a)*(p-b)*(p-c));
      printf("a=%7.2f,b=%7.2f,c=%7.2f\n",a,b,c);
      printf("area=%8.3f\n",area);
      return 0;
   }
   else{ printf(“输入的三条边不能构成三角形!”);return -1;}
}
