#include <cstdio>
#include <iostream>
using namespace std;
int a[100005];
int main()
{
	int n,m,k,l,r,v;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	while(m--)
	{
		scanf("%d%d%d",&k,&l,&r);
		if(k==1)
		{
			scanf("%d",&v);
			if(v==1) continue;//注意细节，能多抢分 
			for(int i=l;i<=r;i++)
				if(a[i]>=v&&a[i]%v==0)
					a[i]/=v;
		}
		else
		{
			long long ans=0;
			for(int i=l;i<=r;i++)
				ans+=a[i];
			printf("%lld\n",ans);
		}
	}
	return 0;
}
