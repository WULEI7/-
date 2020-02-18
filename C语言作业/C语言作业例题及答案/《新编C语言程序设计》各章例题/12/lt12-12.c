#include <stdio.h>
#define NUM ok
main(){
   struct student
   {  int num;
      char *name;
      char sex;
      float score;
   } *ps;
   ps=(struct student*)malloc(sizeof(struct student));
   ps->num=102;
   ps->name="Zhang ping";
   ps->sex='M';
   ps->score=62.5;
   #ifdef NUM
      printf("Number=%d\nScore=%f\n",ps->num,ps->score);
   #else
      printf("Name=%s\nSex=%c\n",ps->name,ps->sex);
   #endif
   free(ps);
}
