#include <stdio.h>
int main()
{
	int n,a[100],b[100],i=0,j=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		b[i]=0;
		for(j=0;j<i;j++)
		if(a[i]>a[j]) b[i]++;
	}
	for(i=0;i<n;i++)
	printf("%d ",b[i]);
	return 0;
}
