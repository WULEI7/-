#include <stdio.h>
#include <stdlib.h>
main()
{  FILE *fp;
char c;
int i=0,no=0,line=0;
if ((fp=fopen("text.txt","wt"))==NULL)
{  printf("can't open this file.\n"); exit(0);}
printf("please input a string.\n");
while((c=getchar())!=EOF)
{
   if(c>='a' && c<='z') c-=32;
   fputc(c,fp);
}
fclose(fp);
if ((fp=fopen("text.txt","r"))==NULL)
{  printf("can't open this file.\n"); exit(0);}
while (!feof(fp))
{  c=fgetc(fp);
   no++;
   if (c=='\n') line++;
}
printf("line=%d character_no=%d\n",line,no);
fclose(fp);
}
