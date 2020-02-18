#include<stdio.h>
main()
{  FILE *fp;int ch;
   if((fp=fopen("c:\\project\\example\\c1.txt","rt"))==NULL)
   { printf("\nCannot open file strike any key exit!");getch();exit(1); }
   ch=fgetc(fp);
   while(ch!=EOF) { putchar(ch); ch=fgetc(fp); }
   fclose(fp);
} 
