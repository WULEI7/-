#include <stdio.h>
void main()
{  int year,month,days=0;
   printf("Input year ,month:");  scanf("%d,%d", &year,&month);
   switch(month)  /*���ղ�ͬ�·ݷֱ���*/ 
   {  case 1: case 3: case 5: case 7: case 8: case 10: 
      case 12:    /*1��3��5��7��8��10��12�¶���31��*/
         days=31; break;               /*�˳��������*/
      case 4: case 6: case 9: case 11: /*4��6��9��11�¶���30��*/
         days=30; break;
      case 2:     /* 2��Ҫ�ж��Ƿ������������ */
         if((year%4==0&&year%100!=0)||year%400==0) days=29;
         else days=28;
         break;
      default:    /* ��ζ���·������д� */
        days=-1;  /* -1�Ǹ����ֵ���ɸ�����ֵ������if���ݴ�ֵ�ж�*/
   }
   if (days!=-1) printf("The days of %d year %d month is %d.\n",year,month,days);
   else printf("Month Error.\n");
}
