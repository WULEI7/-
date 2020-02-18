#include <stdio.h>
#include <string.h>
void main()
{  char string[20],str[3][20]; int i;
   for (i=0;i<3;i++) gets(str[i]);
   if (strcmp(str[0],str[1])>0) strcpy(string,str[0]);
   else strcpy(string,str[1]);
   if (strcmp(str[1],str[2])<0) strcpy(string,str[2]);
   puts(string);
}
