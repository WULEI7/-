#include <stdio.h>
int main()
{
int a,b,max;              /* �������� */
scanf("%d,%d",&a,&b);     /* �������ֵ */
max=a;                  /* �Ȱ�a��Ϊ�ϴ��� */
if(max<b) max=b;         /* ͨ���Ƚ��ж��ϴ����Ƿ���b */
printf("max=%d",max);     /* ����ϴ��� */
return 0;
}
