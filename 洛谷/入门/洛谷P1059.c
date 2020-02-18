#include <stdio.h>
int main()
{
	int n,a[100],i,j,k=0,flag=0,temp;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++)
			if(a[i]>a[j])
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
	for(i=0;i<n-1;i++)
	{
		flag=0;
		for(j=i+1;j<n;j++)
			if(a[i]==a[j]) flag=1;
		if(flag==1) continue;
		a[k]=a[i];
		k++;
	}
	a[k]=a[n-1];
	printf("%d\n",k+1);
	for(i=0;i<=k;i++)
		printf("%d ",a[i]);
	return 0;
}
