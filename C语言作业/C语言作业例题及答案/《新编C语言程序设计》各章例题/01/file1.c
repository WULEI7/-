// file1.c����CԴ�����ļ�1����main()��max()����
#include<stdio.h>
main()                          /*������*/
{
   int x,y,z;                   /*����˵��*/
   FILE *fpi,*fpo;
   //int max(int a,int b);        /*�ڲ���������*/
   //extern int min(int a,int b); /*�ⲿ��������*/
   if((fpi=fopen("infile.txt","r"))==NULL) /*��infile.txt�����ļ�*/
   {
      printf("Input two numbers:\n");/*����ʧ�ܣ�����ʾ�Ӽ�������*/
      scanf("%d%d",&x,&y);           /*�Ӽ�������x,yֵ*/
   }
   else     /*�����ļ��ɹ������infile.txt�ļ�������*/
   {
      fscanf(fpi,"%d%d",&x,&y);      /*���ļ�����x,yֵ*/
      fclose(fpi);                   /*�ر��ļ�ָ��fpi*/
   }
   z=max(x,y);                       /*����max����*/
   fpo=fopen("outfile.txt","w");     /*��outfile.txt����ļ�*/
   fprintf(fpo,"Two numbers are %d, %d\n",x,y);/*����������ļ�*/
   fprintf(fpo,"Max number is %d\n",z);        /*������ֵ���ļ�*/
   fprintf(fpo,"Min number is %d\n", min(x,y));/*�����Сֵ���ļ�*/
   fclose(fpo);                                /*�ر��ļ�ָ��fpo*/
   printf("Two numbers are %d, %d\n",x,y);     /*�������������ʾ��*/
   printf("Max number is %d\n",z);             /*������߼����ֵ����ʾ��*/
   printf("Min number is %d\n", min(x,y));     /*������߼���Сֵ����ʾ��*/
}
