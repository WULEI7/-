#include <stdio.h>
#include <math.h>
int main()
{
	int n,i,a[1000],b=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=1;i<n;i++)
	{
		if(abs(a[i]-a[i-1])>b) b=abs(a[i]-a[i-1]);
	}
	printf("%d",b);
	return 0;
}
