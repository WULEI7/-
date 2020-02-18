#include <stdio.h>
int main()
{
	int n,i,j,a[100]={0};
	scanf("%d",&n);
	printf("%d\n",n); 
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(j==i) continue;
			else if(a[j]==0) a[j]=1;
			else if(a[j]==1) a[j]=0;
		}
		for(j=0;j<n;j++)
			printf("%d",a[j]);
		printf("\n");
	}
	return 0;
}
