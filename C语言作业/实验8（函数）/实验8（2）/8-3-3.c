#include <stdio.h>
#include <string.h>
#define MAX 80
void Insert(char s[]);
main()
{  char string[2*MAX];
   scanf("%s",string);
   Insert(string);
   printf("%s",string);
}
void Insert(char srcStr[])
{  char strTemp[MAX]; int i=0,j=0;
   strcpy(strTemp,srcStr);
   while(strTemp[j]!='\0')
   {  srcStr[i++]=strTemp[j];
      j++;
      srcStr[i++]=' ';
   }
   srcStr[i]= '\0';
}

