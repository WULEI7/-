#include <stdio.h>
int main()
{
	int n,i,j,a[20],sum=0,max=0,t;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<n;i++)
		sum+=a[i];
	if(sum<0) printf("NO\n");
	else
	{
		printf("YES\n");
		for(i=0;i<n;i++)
		{
			t=a[i];
			if(t>max) max=t;
			for(j=i+1;j<n;j++)
			{
				t+=a[j];
				if(t>max) max=t;
			}
		}
		printf("%d",max);
	}
	return 0;
}
