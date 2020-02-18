#include <stdio.h>
int main()
{
	int a[101],i=0,j,k;
	for(i=0;i<=100;i++)
	{
	    scanf("%d",&a[i]);
	    if(a[i]==0) break;
	    j=i-1;
	}
	for(j=i-1;j>=0;j--)
	printf("%d ",a[j]);
	return 0;
}
