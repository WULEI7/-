#include <stdio.h>
main(){
   int a,b,max;
   printf("input two numbers: ");scanf("%d%d",&a,&b);
   max=a;                 // ��˼���ȼ���aΪ��������������ã�
   if (max<b) max=b;      // Ȼ���õ�ǰ�����ֵmax��b���Ƚ�
   printf("max=%d\n",max);// ������ߵ����ֵ
}
