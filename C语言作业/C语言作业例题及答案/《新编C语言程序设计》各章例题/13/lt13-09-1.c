#include <stdio.h>
void printbit(int x,int n)
{ if(n>0)
  { putchar('0'+((unsigned)(x&(1<<(n-1)))>>(n-1)));/*�����nλ��ע����������������*/
    printbit(x,n-1); /*�ݹ���ã����x�ĺ�n-1λ*/
  }
}
void main()
{ int i,x;printf("Input number:"); scanf("%d",&x);
  printf("The number of decimal form is %d\n",x);printf("It's binary form is ");
  printbit(x,sizeof(int)*8);/*x:������sizeof(int):int�����ڴ�����ռ���ֽ�����sizeof(int)*8:int�Ͷ�Ӧ�Ķ�����λ��*/
  putchar('\n');
}
