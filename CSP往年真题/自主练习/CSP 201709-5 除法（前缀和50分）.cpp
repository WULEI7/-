#include <cstdio>
long long sum[100005];
int n,m,a[100005];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		sum[i]+=(sum[i-1]+a[i]);
	}
	for(int i=1;i<=m;i++)
	{
		int opt,l,r,w;
		scanf("%d %d %d",&opt,&l,&r);
		if(opt==2) printf("%lld\n",sum[r]-sum[l-1]);
		else
		{
			scanf("%d",&w);
			if(w==1)continue;
			while(l<=r)
			{
				if(a[l]>=w&&a[l]%w==0)
				{
					for(int i=l;i<=n;i++)//注意要更新到最后 
						sum[i]-=(a[l]-a[l]/w);
					a[l]/=w;
				}
				l++;
			}
		}
	}
	return 0;
}
