#include <stdio.h>
#define N 30
struct student
{   int score;     /*ѧ���ɼ�*/
   char name[10]; /*ѧ������*/
} s[N];
void main()
{  int i,score90,score80,score70,score60,score_failed;
   for(i=0;i<N;i++)
      scanf("%d%s",&s[i].score,s[i].name);/*����N��ѧ���ɼ�����������������s��*/
   score90=0;score80=0;score70=0;score60=0;score_failed=0;
   for(i=0;i<N;i++)
   {  switch (s[i].score/10)
      {
          case 10:
          case 9:score90++;break;
          case 8:score80++;break;
          case 7:score70++;break;
          case 6:score60++;break;
          default:score_failed++;
      }
   }
   printf("�ţ�%d����%d�У�%d����%d������%d\n",score90,score80,score70,score60,score_failed);
}
