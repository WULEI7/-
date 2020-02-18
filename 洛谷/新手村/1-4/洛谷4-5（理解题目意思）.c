#include <stdio.h>
int main()
{
	int n,a[100],b[100]={0},t,i,j,k,s=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<n;i++)
		for(j=i+1;j<n;j++)
			if(a[i]>a[j])
			{
				t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
	for(i=0;i<n;i++)
		for(j=i+1;j<n;j++)
			for(k=j+1;k<n;k++)
				if(a[i]+a[j]==a[k]&&b[k]==0)
				{
				s++;
				b[k]=1;
				}
	printf("%d",s);
	return 0;
}
