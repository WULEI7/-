#include <math.h>
#include <stdio.h>
void main()
{  float b,c,arg,area;            /*����ʵ�ͱ���*/
   printf("Please input b, c ,arg:");
   scanf("%f%f%f", &b, &c, &arg); /*�Ӽ�����������ʵ��������argΪ����*/
   area = b*c*sin(arg)/2;
   printf("area = %0.2f\n", area);/*0.2��ʾ������λС�����*/
}
