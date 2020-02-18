#include <stdio.h>
int len(char s[])
{  char *p=s;
   while (*p!= '\0') p++;
   return p-s;
}
main()
{  char str[80]; gets(str);
   printf("\"%s\" include %d characters.\n",str,len(str));
}
