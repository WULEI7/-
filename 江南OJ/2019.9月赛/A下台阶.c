#include <stdio.h>
int main()
{
	long long int a[51];
	int n,i;
	a[1]=1;a[2]=2;a[3]=4;
	for(i=4;i<=50;i++)
	a[i]=a[i-3]+a[i-2]+a[i-1];
	scanf("%d",&n);
	printf("%lld",a[n]);
	return 0;
 } 
