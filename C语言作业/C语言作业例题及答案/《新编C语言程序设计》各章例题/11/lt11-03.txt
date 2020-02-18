#include <stdio.h>
#include <conio.h> 
main(int argc,char *argv[])
{  FILE *fp1,*fp2; char ch;
   if(argc==1)
   {  printf("have not enter file name strike any key exit");getch(); exit(0);}
   if((fp1=fopen(argv[1],"rt"))==NULL)
   {  printf("Cannot open %s\n",argv[1]);getch(); exit(1);}
   if(argc==2) fp2=stdout; // stdout标准输出文件指针
   else if((fp2=fopen(argv[2],"wt+"))==NULL)
   {  printf("Cannot open %s\n",argv[1]); getch(); exit(1);}
   while((ch=fgetc(fp1))!=EOF) fputc(ch,fp2);
   fclose(fp1); fclose(fp2);
}
