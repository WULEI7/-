#include <stdio.h>
void main() 
{   int year,leap;  //变量作为标志变量，leap取值1为闰年，0为非闰年
    printf("Please input the year:");
    scanf("%d",&year);
    if (year % 4 == 0)         /*被4整除*/
    {   
        if (year%100 == 0)     /*被100整除*/  /*内嵌2层if*/
        {   if (year%400 == 0) /*被400整除*/  /*内嵌3层if*/
                leap = 1;
            else leap = 0;
        }
        else leap = 1;
    }
    else leap = 0;             /*不能被4整除  */
    if (leap) printf("%d is a leap year\n",year);
    else printf("%d is not a leap year\n",year);
}
