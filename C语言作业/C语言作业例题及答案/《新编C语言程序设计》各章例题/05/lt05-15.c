#include <stdio.h>
#include <math.h>
void main()
{  float a, b, c, disc, p, q, x1, x2;
   printf("Please enter the coefficients a,b,c:");
   scanf("%f,%f,%f", &a, &b, &c);
   if(a==0) printf("Error.");/*判断是否是一元二次方程*/
   else
   {   disc = b * b - 4 * a * c; 
       if(disc>=0)           /*嵌套分支语句，判断方程是否有实根*/
       {  p = -b / (2*a);  q = sqrt(disc) / (2*a);
          x1 = p + q; x2 = p - q;
          printf("x1=%7.4f, x2=%7.4f\n", x1, x2);
       }
       else printf("no real root!");
   }
}
