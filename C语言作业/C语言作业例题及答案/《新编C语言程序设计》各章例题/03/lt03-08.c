#include <stdio.h>
main(){
   union       //���干�������u1����������½�
   {  int i;   // int i��float f����4���ֽ�
      float f; // i��f���ã���ζ�Ŵ���f���������������ݿ�����ͨ��i�����
   } u1;
   u1.f=(float)120.5;
   printf("%d  %o   %x\n",u1.i,u1.i,u1.i);
}
