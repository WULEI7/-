#include <stdlib.h>  /*srand()和rand()函数的头文件*/
#include <stdio.h>
void main()
{ unsigned int n;
  printf("Please input n:"); scanf("%u", &n);
  srand(n);  /*种子函数，初始化rand()。Win-TC中也可用randomize()来初始化*/
  printf("%8d",rand());/*调用rand()函数一次，输出一个随机数。Win-TC可用random(n)*/
  printf("%8d",rand());  /*调用rand()函数一次，输出下一个随机数*/
  printf("%8d\n",rand());/*调用rand()函数一次，输出下一个随机数*/
}
