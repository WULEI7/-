#include <iostream>
#include <cstdio> 
#include <string>
#include <cstring>
using namespace std;
int ql,qr,x,d,temp[50005],a[50005*4];
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
		a[o]=a[ls]+a[rs];
	}
}//建线段树 
int query(int o,int l,int r)
{
	if(ql<=l&&r<=qr)
		return a[o];
	else
	{
		int m=(l+r)/2;
		int ls=2*o,rs=2*o+1;
		int sum=0;
		if(ql<=m)
			sum+=query(ls,l,m);
		if(qr>=m+1)
			sum+=query(rs,m+1,r);
		return sum;
	}
}//查询 
void update(int o,int l,int r)
{
	if(l==r)
		a[o]+=d;
	else
	{
		int m=(l+r)/2;
		int ls=2*o,rs=2*o+1;
		if(x<=m)
			update(ls,l,m);
		else
			update(rs,m+1,r);
		a[o]=a[ls]+a[rs];
	}
}//修改 
int main()
{
	int t;
	cin>>t;
	for(int T=1;T<=t;T++)
	{
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>temp[i];
		build(1,1,n);
		/*memset(a,0,sizeof(a)); 
		for(int i=1;i<=n;i++)
		{
			x=i,d=temp[i];
			update(1,1,n);
		}*/
		printf("Case %d:\n",T);
		string s;
		int a,b;
		while(cin>>s)
		{
			if(s=="Query")
			{
				cin>>a>>b;
				ql=a,qr=b;
				printf("%d\n",query(1,1,n));
			}
			else if(s=="Add")
			{
				cin>>a>>b;
				x=a,d=b;
				update(1,1,n);
			}
			else if(s=="Sub")
			{
				cin>>a>>b;
				x=a,d=-b;//减去即加上负数 
				update(1,1,n);
			}
			else break;
		}
	}
	return 0;
}
