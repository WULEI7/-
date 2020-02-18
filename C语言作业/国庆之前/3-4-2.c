#include<stdio.h>
int main()
{
	int a,b,c,e;
	double d;
	scanf("%d,%d,%d",&a,&b,&c);
	d=1.0*(a+b+c)/3;
	e=a*b*c;
	printf("%d,%d和%d的平均值为%.2lf,积为%d",a,b,c,d,e);
	return 0;
}

