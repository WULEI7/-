#include <stdio.h>
main(){
   int a,b,c,max,min;
   printf("input three numbers: ");  scanf("%d%d%d",&a,&b,&c);
   if(a>b)
      {max=a;min=b;}
   else
      {max=b;min=a;}
   if(max<c)                                                  if(max<c)max=c;
      max=c;   //��ʱc����������С,min���ֲ���               if(min>c)min=c;
   else
      if(min>c)
         min=c;//��ʱc�����������,max���ֲ���
      //else; ��ʡ�ԣ��˷�֧c����С����Ӱ��������С��
   printf("max=%d\nmin=%d\n",max,min);
}
���Ƶ��������������ֵ���������������ʽ����ʵ�֣��������£�
void main()
{  int a,b,c,max;                  /* ������� */
   printf("Input a,b,c:\n");       /* ��ʾ��Ϣ */
   scanf("%4d%4d%4d", &a, &b, &c); /* ���뺯�� */
   max=a>b?a:b;                 /* �����������ֵ */
   max=max>c?max:c;             /* ����k�Ƚϣ������������ֵ */
   printf("The maxmum value of the three data is %d\n", max); /*���*/
}
