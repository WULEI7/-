#include <stdio.h>
#include <math.h>
void main()
{  float a, b, c, disc, p, q, x1, x2;
   printf("Please enter the coefficients a,b,c:");
   scanf("%f,%f,%f", &a, &b, &c);
   if(a==0) printf("Error.");/*�ж��Ƿ���һԪ���η���*/
   else
   {   disc = b * b - 4 * a * c; 
       if(disc>=0)           /*Ƕ�׷�֧��䣬�жϷ����Ƿ���ʵ��*/
       {  p = -b / (2*a);  q = sqrt(disc) / (2*a);
          x1 = p + q; x2 = p - q;
          printf("x1=%7.4f, x2=%7.4f\n", x1, x2);
       }
       else printf("no real root!");
   }
}
