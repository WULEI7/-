#include <stdlib.h>
#include <time.h>  // time()所需的头文件
#include <stdio.h>
void main()
{  unsigned short count;
   srand((unsigned)time(NULL));  /*种子函数*/
   count= rand()%100+3; printf("%hu\n",count);
   count= rand()%100+3; printf("%hu\n",count);
   count= rand()%100+3; printf("%hu\n",count);
}
