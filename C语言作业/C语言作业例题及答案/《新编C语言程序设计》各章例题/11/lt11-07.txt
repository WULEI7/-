#include <stdio.h>
struct student{char name[10];int num;int age;char addr[15];}stua[2],stub[2],*pp,*qq;
main()
{  FILE *fp; char ch; int i;
   pp=stua; qq=stub;
   if((fp=fopen("stu_list ","wb+"))==NULL)
   { printf("Cannot open file strike any key exit!"); getch(); exit(1); }
   printf("\ninput data\n");
   for(i=0;i<2;i++,pp++) scanf("%s%d%d%s",pp->name,&pp->num,&pp->age,pp->addr);
   pp=stua;
   for(i=0;i<2;i++,pp++)
     fprintf(fp,"%s %d %d %s\n",pp->name,pp->num,pp->age,pp->addr);
   rewind(fp);
   for(i=0;i<2;i++,qq++)
     fscanf(fp,"%s %d %d %s\n",qq->name,&qq->num,&qq->age,qq->addr);
   printf("\n\nname\tnumber      age      addr\n");
   qq=stub;
   for(i=0;i<2;i++,qq++)
      printf("%s\t%5d  %7d      %s\n",qq->name,qq->num, qq->age, qq->addr);
   fclose(fp);
}
