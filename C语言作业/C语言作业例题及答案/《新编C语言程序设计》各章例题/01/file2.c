static int max(int a,int b)   /*����max����*/
{
   if(a>b) return a;   /*�ѽ��������������������*/
   else return b;
}


/* file2.c����CԴ�����ļ�2����min()���� */
 int min(int a,int b)  /*����min����*/
{
   int result;
   result= a<b?a:b;   /*ʹ��?:����������õ���С��*/
   return result;     /*������Сֵ*/
}
