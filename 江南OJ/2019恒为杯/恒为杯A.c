#include <stdio.h>
int main()
{
	int n,i,flag[10]={0};
	long long a[10],sum;
	while(scanf("%d",&n)!=EOF)
	{
		sum=1;flag=2;
		for(i=0;i<n;i++)
			scanf("%lld",&a[i]);
		for(i=0;i<n;i++)
		{
			if(a[i]>1e9) {printf("yes\n");flag=1;break;}
			sum*=a[i];
			if(sum>1e9) {printf("yes\n");flag=1;break;}
		}
		if(flag==2&&sum<1e8) printf("no\n");
		if(flag==2&&sum>=1e8&&sum<=1e9) printf("maybe\n");
	}
	return 0;
}
