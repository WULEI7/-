#include <stdio.h>
int isprime(int x)
{
	int pd=1,z;
	if(x!=2&&x%2==0) pd=0;
	if(x%2==1)
	{
		for(z=2;z<x;z++)
			if(x%z==0) 
			{pd=0;break;}
	}
	return pd;
}
int main()
{
	int n,i,j,a[20];
	scanf("%d",&n);
	for(i=0;i<n;i++)
		a[i]=i+1;
	for(i=0;i<n;i++)
		printf("%d ",isprime(a[i]));
	return 0;
	
}
