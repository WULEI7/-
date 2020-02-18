#include <stdio.h>
void main()
{  FILE *fp; /*定义文件指针*/
   char ch;
   if((fp=fopen("string","wb+"))==NULL) /*以读写方式打开文件*/
   { printf("Cannot open file strike any key exit!"); getch(); exit(1); }
   printf("input a string:\n");
   ch=getchar();     /*读入一行字符，每次只读一个*/
   while (ch!='\n')
   {   fputc(ch,fp); /*写字符到文件中*/
       ch=getchar(); /*读下一个字符*/
   }
   if((fp=fopen("string","rb"))==NULL)  /* 以读方式打开文件 */
   { printf("Cannot open file strike any key exit!"); getch(); exit(2); }
   ch=fgetc(fp);     /*读第一个字符*/
   while(ch!=EOF)
   {    putchar(ch); /*输出字符*/
        ch=fgetc(fp);/*读下一个字符*/
   }
   printf("\n");fclose(fp); /*关闭文件*/
}
