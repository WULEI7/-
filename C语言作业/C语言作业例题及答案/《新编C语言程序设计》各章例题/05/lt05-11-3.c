#include <stdio.h>
void main()
{  int a,b,c,max;                  /* ������� */
   printf("Input a,b,c:\n");       /* ��ʾ��Ϣ */
   scanf("%4d%4d%4d", &a, &b, &c); /* ���뺯�� */
   max=a>b?a:b;                 /* �����������ֵ */
   max=max>c?max:c;             /* ����k�Ƚϣ������������ֵ */
   printf("The maxmum value of the three data is %d\n", max); /*���*/
}
