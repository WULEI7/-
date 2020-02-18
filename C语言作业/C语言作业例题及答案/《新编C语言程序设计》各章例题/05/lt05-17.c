#include <stdio.h>
void main()
{  int year,month,days=0;
   printf("Input year ,month:");  scanf("%d,%d", &year,&month);
   switch(month)  /*按照不同月份分别处理*/ 
   {  case 1: case 3: case 5: case 7: case 8: case 10: 
      case 12:    /*1、3、5、7、8、10、12月都是31天*/
         days=31; break;               /*退出开关语句*/
      case 4: case 6: case 9: case 11: /*4、6、9、11月都是30天*/
         days=30; break;
      case 2:     /* 2月要判断是否是闰年后定天数 */
         if((year%4==0&&year%100!=0)||year%400==0) days=29;
         else days=28;
         break;
      default:    /* 意味着月份输入有错 */
        days=-1;  /* -1是个标记值，可赋其他值，后续if语句据此值判断*/
   }
   if (days!=-1) printf("The days of %d year %d month is %d.\n",year,month,days);
   else printf("Month Error.\n");
}
