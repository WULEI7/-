#include<bits/stdc++.h>
using namespace std;
int n,m,bit[500005],a[500005],p[1000005],ans[200005];
int query(int x)
{
	int sum=0;
	while(x)
	{
		sum+=bit[x];
		x-=x&-x;
	}
	return sum;
}
void add(int x,int k)
{
	while(x<=n)
	{
		bit[x]+=k;
		x+=x&-x;
	}
}
struct ask
{
	int l,r,id;
}q[200005];
bool cmp(const ask &a, const ask &b)
{
	return a.r<b.r;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&q[i].l,&q[i].r);
		q[i].id=i;
	}
    sort(q+1,q+m+1,cmp);
	int r=0;
	for(int i=1;i<=m;i++)
	{
		while(r<q[i].r)
		{
			r++;
			add(r,1);
			if(p[a[r]])
				add(p[a[r]],-1);
			p[a[r]]=r;
		}
		ans[q[i].id]=query(r)-query(q[i].l-1);
	}
	for(int i=1;i<=m;i++)
		printf("%d\n",ans[i]);
	return 0;
}
