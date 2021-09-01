#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,l[500005],r[500005],a[500005],p[500005];
int query(int x,int *bit)
{
	int sum=0;
	while(x)
	{
		sum+=bit[x];
		x-=x&-x;
	}
	return sum;
}
void add(int x,int k,int *bit)
{
	while(x<=n)
	{
		bit[x]+=k;
		x+=x&-x;
	}
}
int sum(int l,int r,int *bit)
{
	return query(r,bit)-query(l-1,bit);
}

signed main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		p[i]=a[i];
	}
    sort(p+1,p+n+1);
    for(int i=1;i<=n;i++)
    {
    	a[i]=lower_bound(p+1,p+n+1,a[i])-p;
    	add(a[i],1,r);
	}
    int ans=0;
    for(int i=1;i<=n;i++)
    {
    	add(a[i],-1,r);
    	ans+=min(sum(a[i]+1,n,l),sum(a[i]+1,n,r));
    	add(a[i],1,l);
	}
    printf("%lld\n",ans);
	return 0;
}
