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
  for(i=sizeof(int)*8;i>=1;i--) putchar('0'+((unsigned)(x&(1<<(i-1)))>>(i-1)));/*输出第i位*/;
  putchar('\n');
}

