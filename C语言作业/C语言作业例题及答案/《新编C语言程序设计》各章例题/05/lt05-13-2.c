#include <stdio.h>
void main()
{  int y; scanf("%d",&y);
   if((y%4==0&&y%100!=0)||y%400==0)  //»ò if(!(y%4)&&y%100||!(y%400))
      printf("%d is a leap year\n",y);
   else printf("%d is not a leap year\n",y);
}
