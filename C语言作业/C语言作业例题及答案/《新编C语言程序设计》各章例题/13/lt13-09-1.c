#include <stdio.h>
void printbit(int x,int n)
{ if(n>0)
  { putchar('0'+((unsigned)(x&(1<<(n-1)))>>(n-1)));/*输出第n位，注意其先左移再右移*/
    printbit(x,n-1); /*递归调用，输出x的后n-1位*/
  }
}
void main()
{ int i,x;printf("Input number:"); scanf("%d",&x);
  printf("The number of decimal form is %d\n",x);printf("It's binary form is ");
  printbit(x,sizeof(int)*8);/*x:整数；sizeof(int):int型在内存中所占的字节数；sizeof(int)*8:int型对应的二进制位数*/
  putchar('\n');
}
