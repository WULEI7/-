#include <stdio.h>
void main()
{  int i=1;
   unsigned int ui=1;
   short int si=1;
   unsigned short int usi=1;
   long int li=1;     //long long ll;C99�������ͣ�VC++ 6.0 ��δ֧��ʵ��
   unsigned long ul=1;//unsigned long long ull;C99�������ͣ�VC++ 6.0��δ֧��ʵ��
   printf("bytes of int:%d\n",sizeof(i)); // ���������ռ�õ��ֽ���
   printf("bytes of unsigned int:%d\n",sizeof(ui));
   printf("bytes of short int:%d\n",sizeof(si));
   printf("bytes of unsigned short int:%d\n",sizeof(usi));
   printf("bytes of long int:%d\n",sizeof(li));
   printf("bytes of unsigned long:%d\n",sizeof(ul));
}
