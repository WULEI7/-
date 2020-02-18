#include <stdio.h>
void main()
{  int a=1,b=2,c,d,e;
   c=(-a++)+(++b);       /* c=-1+3=2,a=2,b=3 */
   d=(b--)+(++a)+a;      /* d=3+3+3=9,a=3,b=2 */
   e=(a/(++b))-(b/(--a));/* b=3,a=2,e=3/3-3/2=0, Win-TCÖÐe=2/3-3/2 */
   printf("c=%d,d=%d,e=%d\n",c,d,e);
}

