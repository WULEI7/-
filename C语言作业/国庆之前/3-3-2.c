#include <stdio.h>
#include <math.h>

int main()
{
   float x=8.0,y;
   y=(1+pow(x,2))/(pow(x,2)+4*pow(x,0.5)+10);
   printf("%f",y);
}
