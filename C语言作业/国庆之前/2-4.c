#include<stdio.h>
int main()
{
	int a,b,c,sum;
	scanf("%d,%d,%d",&a,&b,&c);	
	sum=a*a*a+b*b*b+c*c*c;
	printf("%d^3+%d^3+%d^3=%d",a,b,c,sum);
	return 0;
}


