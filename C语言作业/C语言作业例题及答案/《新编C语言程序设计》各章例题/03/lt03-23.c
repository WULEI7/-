#include <stdio.h>
void main(){
   int a=2,b=4,c=6,x,y;
   y=(x=a+b),(b+c);     // 注意(,)运算优先级最低。为此y的值不是10
   printf("y=%d,x=%d",y,x);
}
