#define  PI  3.14159  /*Ԥ��������*/
#include <stdio.h>
void main()
{  float r,area,circumference;  /*����ʵ������*/
   printf("Please input r:");   /*��ʾ��ʾ��Ϣ*/
   scanf("%f",&r);              /*�Ӽ��̶�ȡһ��ʵ��r*/
   area= PI * r * r;            /*�������������area����*/
   circumference =2 * PI * r;   /*�����ܳ�������circumference����*/
   printf("area = %f\n", area); /*������*/
   printf("circumference = %f\n",circumference); /*����ܳ�*/
}
