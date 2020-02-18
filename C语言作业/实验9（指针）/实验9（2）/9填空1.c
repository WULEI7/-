#include <stdio.h> 
#include<string.h>
chnum(char *p);
void main()
{  char str[6];
   int n;
   gets(str);
   if (*str=='-') n=-chnum(str+1);
   else n=chnum(str);
   printf("%d\n",n);
}
chnum(char *p)
{  int num=0,k,len,j;
   len=strlen(p);
   for(;*p!='\0';p++)
   {  k=*p-'0';
      j=(--len);
      while (j-->0) 
	  {k=k*10;}
      num=num+k;
   }
   return(num);
}
