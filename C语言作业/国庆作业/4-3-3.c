#include <stdio.h>
int main()
{
   int x,y,t;
printf("请输入 x,y:\n");
scanf("%d,%d",&x,&y);
if (x<y)                           
t=x,x=y,y=t;
printf("交换后的 x=%d,y=%d\n",x,y);
}
