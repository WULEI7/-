#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int ql,qr,x,d,temp[200005],a[200005*4];
void build(int o,int l,int r)
{
	if(l==r)
		a[o]=temp[l];
	else
	{
		int m=(l+r)/2;
		int ls=2*o,rs=2*o+1;
		build(ls,l,m);
		build(rs,m+1,r);
		a[o]=max(a[ls],a[rs]);
	}
}//建树 
int query(int o,int l,int r)
{
	if(ql<=l&&r<=qr)
		return a[o];
	int m=(l+r)/2;
	int ls=2*o,rs=2*o+1;
	int ans=0;
	if(ql<=m)
		ans=max(ans,query(ls,l,m));
	if(qr>=m+1)
		ans=max(ans,query(rs,m+1,r));
	return ans;
}//查询 
void update(int o, int l, int r)
{
	if(l==r)
		a[o]=d;
	else
	{
		int m=(l+r)/2;
		int ls=2*o,rs=2*o+1;
		if(x<=m)
			update(ls,l,m);
		else
			update(rs,m+1,r);
		a[o]=max(a[ls],a[rs]);
	}
}//修改 
int main()
{
	int n,t;
	while(~scanf("%d%d",&n,&t))//注意有多组数据 
	{
		for(int i=1;i<=n;i++)
			scanf("%d",&temp[i]);
		build(1,1,n);
		while(t--)
		{
			string s;
			s.resize(1);
			scanf("%s",&s[0]);//注意字符或字符串的读入 
			if(s=="Q")
			{
				scanf("%d%d",&ql,&qr);
				printf("%d\n",query(1,1,n));
			}
			else if(s=="U")
			{
				scanf("%d%d",&x,&d);
				update(1,1,n);
			}
		}
	}
	return 0;
}
