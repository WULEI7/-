#include <stdio.h>
#define S1(a,b) a*b
#define S2(a,b) ((a)*(b))
#define max(a,b) ((a)>(b)?(a):(b))
void main()
{  int x=3, y=4, i=5, j=6, s, z;
   s=S1(x+y, x-y); /* s=x+y*x-y; s==11 */
   s=S2(x+y, x-y); /* s=((x+y)*(x-y)); s==-7 */
   z=max(i++, j++); /* z=((i++)>(j++)?(i++):(j++)); */
   /* z==7, i==6, j==8 */
}

