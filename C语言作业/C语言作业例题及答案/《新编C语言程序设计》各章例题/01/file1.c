// file1.c——C源程序文件1，含main()与max()函数
#include<stdio.h>
main()                          /*主函数*/
{
   int x,y,z;                   /*变量说明*/
   FILE *fpi,*fpo;
   //int max(int a,int b);        /*内部函数声明*/
   //extern int min(int a,int b); /*外部函数声明*/
   if((fpi=fopen("infile.txt","r"))==NULL) /*打开infile.txt输入文件*/
   {
      printf("Input two numbers:\n");/*若打开失败，则提示从键盘输入*/
      scanf("%d%d",&x,&y);           /*从键盘输入x,y值*/
   }
   else     /*若打开文件成功，则从infile.txt文件读两数*/
   {
      fscanf(fpi,"%d%d",&x,&y);      /*从文件输入x,y值*/
      fclose(fpi);                   /*关闭文件指针fpi*/
   }
   z=max(x,y);                       /*调用max函数*/
   fpo=fopen("outfile.txt","w");     /*打开outfile.txt输出文件*/
   fprintf(fpo,"Two numbers are %d, %d\n",x,y);/*输出两数到文件*/
   fprintf(fpo,"Max number is %d\n",z);        /*输出最大值到文件*/
   fprintf(fpo,"Min number is %d\n", min(x,y));/*输出最小值到文件*/
   fclose(fpo);                                /*关闭文件指针fpo*/
   printf("Two numbers are %d, %d\n",x,y);     /*输出两两数到显示屏*/
   printf("Max number is %d\n",z);             /*输出两者间最大值到显示屏*/
   printf("Min number is %d\n", min(x,y));     /*输出两者间最小值到显示屏*/
}
