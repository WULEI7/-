#include <stdio.h>
void main()
{  float score; int idj;
   scanf("%f", &score); /*����ɼ�*/
   if (score<0 || score>100) { printf(��Error score!��); return 1; }
   idj=score/10;        /*ȡʮλ���λ*/
   switch(idj)
   {   case 10:
       case 9:
          putchar('A');
          break;        /*break�˳�switch���*/
       case 8:
          putchar('B'); break;
       case 7: putchar('C'); break;
       case 6: putchar('D'); break;
       default: putchar('E');
   }
}
