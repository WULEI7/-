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
  for(i=sizeof(int)*8;i>=1;i--) putchar('0'+((unsigned)(x&(1<<(i-1)))>>(i-1)));/*�����iλ*/;
  putchar('\n');
}

