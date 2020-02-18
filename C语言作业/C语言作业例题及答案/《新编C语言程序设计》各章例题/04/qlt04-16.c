#include <stdio.h>
void main(){
   int a; printf("input a number\n");
   scanf("%d",&a);
   printf("%ld",a);  //a是int类型与 格式符%ld不一致
}
