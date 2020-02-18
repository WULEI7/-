#include<stdio.h>
void main()
{  int i=1;
   printf("%d,%d ",i,i++);  printf("i=%d\n",i); i=1;
   printf("%d,%d ",i,(i++));  printf("i=%d\n",i); i=1;
   printf("%d,%d ",i,(i++,i++));  printf("i=%d\n",i); i=1;
   printf("%d,%d ",i,(i++,i++,i++));  printf("i=%d\n",i); i=1;
   printf("%d,%d ",i,(i++,i+1,i++,i+1));  printf("i=%d\n",i); i=1;
   printf("%d,%d ",(i++,i++),i);            printf("i=%d\n",i);
}
