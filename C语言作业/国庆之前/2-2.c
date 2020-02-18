#include <stdio.h>
int main()
{
   int a,b,sum;
	printf("Please Input a,b\n");
	scanf("%d %d",&a,&b);
	sum=a*a+b*b;
	printf("%d*%d+%d*%d=%d\n",a,a,b,b,sum);
	return 0;
}
