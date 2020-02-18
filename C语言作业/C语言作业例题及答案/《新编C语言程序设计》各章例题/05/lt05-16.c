#include <stdio.h>
void main()
{  float score; int idj;
   scanf("%f", &score); /*输入成绩*/
   if (score<0 || score>100) { printf(“Error score!”); return 1; }
   idj=score/10;        /*取十位与百位*/
   switch(idj)
   {   case 10:
       case 9:
          putchar('A');
          break;        /*break退出switch语句*/
       case 8:
          putchar('B'); break;
       case 7: putchar('C'); break;
       case 6: putchar('D'); break;
       default: putchar('E');
   }
}
