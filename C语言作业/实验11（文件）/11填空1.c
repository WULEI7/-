#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void main()
{    FILE *fp; int i=0;
char str[][20]={"visual C++", "visual Basic", "visual java", "visual foxpro"};
char s[20];
if ((fp=fopen("file11_34.dat","wb"))==NULL)
{ printf("%s不能打开\n","file11_34.dat"); exit(1); }
while(i<4)
{
   fwrite(str[i],20,1,fp);
   i++;
}
fclose(fp);
if ((fp=fopen("file11_34.dat","rb"))==NULL)
{ printf("%s不能打开\n","file11_34.dat"); exit(1); }
fread(s,20,1,fp);
while(!feof(fp))
{
   printf("%s\n",s);
   fread(s,20,1,fp);
}
fclose(fp);
}
