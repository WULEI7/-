#include <stdio.h>
main()
{  FILE *fp; char ch,st[20];
   if((fp=fopen("string.txt","at+"))==NULL)
   { printf("Cannot open file strike any key exit!"); getch(); exit(1);}
   printf("input a string:\n"); scanf("%s",st);
   fputs(st,fp);
   rewind(fp);
   ch=fgetc(fp);
   while(ch!=EOF){ putchar(ch); ch=fgetc(fp);}
   printf("\n"); fclose(fp);
}
