#include <stdio.h>
void main()  /*main������������İ뾶�����Բ��������ܳ�*/
{  float r,area,circumference;     /*����ʵ������*/
   printf("Please input r:");      /*��ʾ��ʾ��Ϣ*/
   scanf("%f",&r);                 /*�Ӽ��̶�ȡһ��ʵ��r*/
   area= 3.1415926 * r * r;        /*�������������area����*/
   circumference=2*3.1415926*r;    /*�����ܳ�������circumference����*/
   printf("area = %f\n", area);    /*������*/
   printf("circumference = %f\n",circumference); /*����ܳ�*/
}

