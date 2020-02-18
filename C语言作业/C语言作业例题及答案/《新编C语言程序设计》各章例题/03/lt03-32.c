#include <stdio.h>
void main()
{  int i=5,j=5,p,q;
   p=(++i)*j;                  /* i=6,p=30 */
   printf("i=%d,p=%d\n",i,p);
   p=(i++)*j;                  /* p=30,i=7 */
   printf("p=%d,i=%d\n",p,i);
   p=(i++)+(i++)+(i++)+(i++);  /* p=28,i=11 */
   q=(++j)+(++j)+(++j) +(++j);  /* j=9,q=31 */
   printf("p=%d,q=%d,i=%d,j=%d\n",p,q,i,j);
}

