#include <stdio.h>
void main()
{  FILE *fp; char ch,st[80];
   if((fp=fopen("string.txt","a"))==NULL) /* 以追加方式打开一个文件 */
   {  printf("Cannot open file strike any key exit!"); getch();
      exit(1);      /* 打开不成功的处理方式 */
   }
   printf("input a string:\n"); 
   scanf("%s",st);  /* 从键盘读入一个串 */
   fputs(st,fp);    /* 将串写入文件中 */
   fclose(fp);
   if((fp=fopen("string.txt","r"))==NULL)
   {  printf("Cannot open file strike any key exit!");getch();
      exit(2);      /* 打开不成功的处理方式 */
   }
   ch=fgetc(fp);    /* 读取文件中的第一个字符 */
   while(ch!=EOF)   /* 反复打印读出的字符，再读下一个字符 */
   {  putchar(ch); ch=fgetc(fp);
   }
   printf("\n");
   fclose(fp);      /* 操作完成，关闭文件 */
}
