#include <stdio.h> 
static struct person
{  char name[20];
   int age;
} person[]={"Li-ming",18, "wang-hua",19, "zhang-ping",20};
main()
{  int i,max,min;
   max=min=person[0].age;
   for(i=1;i<3;i++)
      if (person[i].age>max) max=person[i].age;
      else if (person[i].age<min) min=person[i].age;
   for(i=0;i<3;i++)
      if (person[i].age!=max&&person[i].age!=min)
      { printf("%s %d\n",person[i].name,person[i].age); break; }
}
