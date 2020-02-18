
/*fileinclude.cнд╪Ч2 */
#include "powers.h"
#define MAX_POWER (10)
void main()
{
   int n;
   printf("number\t exp2\t exp3\t exp4\n");
   printf("----\t----\t-----\t------\n");
   for(n=1;n<=MAX_POWER;n++)
   printf("%2d\t%3d\t%4d\t%5d\n",n,sqr(n),cube(n), quad(n));
}
