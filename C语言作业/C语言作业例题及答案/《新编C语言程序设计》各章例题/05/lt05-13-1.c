#include <stdio.h>
void main() 
{   int year,leap;  //������Ϊ��־������leapȡֵ1Ϊ���꣬0Ϊ������
    printf("Please input the year:");
    scanf("%d",&year);
    if (year % 4 == 0)         /*��4����*/
    {   
        if (year%100 == 0)     /*��100����*/  /*��Ƕ2��if*/
        {   if (year%400 == 0) /*��400����*/  /*��Ƕ3��if*/
                leap = 1;
            else leap = 0;
        }
        else leap = 1;
    }
    else leap = 0;             /*���ܱ�4����  */
    if (leap) printf("%d is a leap year\n",year);
    else printf("%d is not a leap year\n",year);
}
