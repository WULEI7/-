#include <stdio.h>
void main()
{  FILE *fp; /*�����ļ�ָ��*/
   char ch;
   if((fp=fopen("string","wb+"))==NULL) /*�Զ�д��ʽ���ļ�*/
   { printf("Cannot open file strike any key exit!"); getch(); exit(1); }
   printf("input a string:\n");
   ch=getchar();     /*����һ���ַ���ÿ��ֻ��һ��*/
   while (ch!='\n')
   {   fputc(ch,fp); /*д�ַ����ļ���*/
       ch=getchar(); /*����һ���ַ�*/
   }
   if((fp=fopen("string","rb"))==NULL)  /* �Զ���ʽ���ļ� */
   { printf("Cannot open file strike any key exit!"); getch(); exit(2); }
   ch=fgetc(fp);     /*����һ���ַ�*/
   while(ch!=EOF)
   {    putchar(ch); /*����ַ�*/
        ch=fgetc(fp);/*����һ���ַ�*/
   }
   printf("\n");fclose(fp); /*�ر��ļ�*/
}
