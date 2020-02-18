#include <stdio.h>
void main()
{  int n,idj,i90,i80,i70,i60,i50; float score;
   i90=i80=i70=i60=i50=0;
   printf("Input n:");scanf("%d", &n); /* 输入考试人数 */
   if (n<=0) {printf(“Error in n’s input!”); exit(1);} //若人数输入错，退出程序。
   while(n--)  /* while循环语句，循环输入n个学生的成绩。循环见下章*/
   {  printf("Input(%d) score[0,100]:",n+1); //倒计数(n不断减少)某学生成绩输入
      scanf("%f", &score);
      if (score<0 || score>100) //若某学生成绩输入错，退出程序。
      { printf(“Error in score’s input!”);exit(2); }
      idj=score/10;  // 获取十位、百位数
      switch(idj)    // 根据成绩分类计数
      {  case 10:
         case 9: i90++;break;
         case 8: i80++;break;
         case 7: i70++;break;
         case 6: i60++;break;
         default: i50++;
      }
   }
   printf("[90-100]有%d人，[80-90)有%d人，[70-80)有%d人，[60-70)有%d人，[0-60)有%d人。\n", i90,i80,i70,i60,i50);
}
