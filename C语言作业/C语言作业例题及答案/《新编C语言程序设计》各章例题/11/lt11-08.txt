#include<stdio.h>
struct student{ char name[10];int num;int age;char addr[15];} stu,*qq;
main()
{  FILE *fp; char ch; int i=1;
   qq=&stu;
   if((fp=fopen("stu_list","rb"))==NULL)
   { printf("Cannot open file strike any key exit!"); getch(); exit(1); }
   rewind(fp);
   fseek(fp,i*sizeof(struct student),0);
   fread(qq,sizeof(struct student),1,fp);
   printf("\n\nname\tnumber      age      addr\n");
   printf("%s\t%5d  %7d      %s\n",qq->name,qq->num,qq->age,qq->addr);
   fclose(fp);
}
