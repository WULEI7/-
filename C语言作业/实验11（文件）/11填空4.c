#include <stdio.h> 
#include <stdlib.h>
void main()
{  FILE *fp; int i=0;
char *str[]={"visual C++", "visual Basic", "visual java", "visual foxpro"};
if ((fp=fopen("file11_33.txt","wt"))==NULL)
{  printf("%s不能打开\n","file11_33.txt"); exit(1); }
while(i<4)
{  fprintf(fp,"%s",str[i]);
   i++;
}
fclose(fp);
}
