#include <stdio.h>
#include <math.h>
/*int isprime(int x)
{
	if(x==2)
		return 1;
	int i;
	for(i=2;i<=sqrt(x);i++)
	{
		if(x%i==0)
			return 0;
	}
	return 1;
}*/
int main()
{
	int a[25],b[1005],cnt=0,n,i,j,flag;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=2;;i++)
	{
		for(j=0;j<n;j++)
		{
			if(a[j]%i==0)
			{
				b[cnt++]=i;
				break;
			}
		}
		for(j=0;j<n;j++)
			while(a[j]%i==0)
				a[j]/=i;
		flag=1;
		for(j=0;j<n;j++)
			if(a[j]>1)
			{
				flag=0;
				break;
			}
		if(flag==1)
			break;
	}
	for(i=0;i<cnt;i++)
		printf("%d ",b[i]);
	return 0;
}
