#include <stdio.h>
#include <math.h>
int main()
{
	long long a[100]={0},b[100]={0},c[100]={0},i,k=0;
	double s;
	while(scanf("%lld",&a[k])!=EOF)
	{
		if(a[k]%2==1)
		{
			b[k]=(a[k]*a[k]-1)/2;
			c[k]=(a[k]*a[k]+1)/2;
		}
		if(a[k]%2==0)
		{
			b[k]=a[k]*a[k]/4-1;
			c[k]=a[k]*a[k]/4+1;
		}
		k++;
	}
	for(i=0;i<k;i++)
		printf("%lld %lld\n",b[i],c[i]);
	return 0;
}
