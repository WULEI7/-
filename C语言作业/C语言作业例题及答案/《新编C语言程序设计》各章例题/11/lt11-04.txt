#include <stdio.h>
main()
{  FILE *fp; char str[11];
   if((fp=fopen("string.txt","rt"))==NULL)
   { printf("\nCannot open file strike any key exit!"); getch(); exit(1);}
   fgets(str,11,fp);
   printf("\n%s\n",str); fclose(fp);
}
