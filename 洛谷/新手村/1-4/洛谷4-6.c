#include <stdio.h>
int main()
{
	int n,a[1000000],i=1,j=1,s=1,max=1;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	scanf("%d",&a[i]);
	
	for(j=1;j<n;j++)
	{
		if(a[j]<a[j+1])
		{
		s++;
		if(s>max) max=s;
		}
		else s=1; 
	}
	printf("%d",max);
	return 0;
}
