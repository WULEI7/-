#include <stdio.h>
int main()
{
   char c1,c2;
   c1=getchar();            /*�Ӽ�������һ��Сд��ĸ*/
   printf("%c,%d\n",c1,c1);  /*�����Сд��ĸ����ASCII��ֵ*/
   c2=c1-32;             /*ת��Ϊ��д��ĸ*/
   printf("%c,%d\n",c2,c2);  /*����ô�д��ĸ����ASCII��ֵ*/
   return 0;
}
