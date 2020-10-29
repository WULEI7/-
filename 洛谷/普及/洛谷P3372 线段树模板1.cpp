#include <iostream>
#include <string>
using namespace std;
int ql,qr;
long long x,temp[100005],a[100005*4],ad[100005*4];
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
long long query(int o,int l,int r,long long d)
{
	if(ql<=l&&r<=qr)
		return a[o]+d*(r-l+1);
	else
	{
		int m=(l+r)/2;
		int ls=2*o,rs=2*o+1;
		long long sum=0;
		if(ql<=m)
			sum+=query(ls,l,m,d+ad[o]);
		if(qr>=m+1)
			sum+=query(rs,m+1,r,d+ad[o]);
		return sum;
	}
}//查询 
void update(int o,int l,int r)
{
	if(ql<=l&&r<=qr)//[ql,qr]区间内的都要加上x 
	{
		a[o]+=x*(r-l+1);
		ad[o]+=x;
		return;
	}
	int m=(l+r)/2;
	int ls=2*o,rs=2*o+1;
	if(ql<=m)
		update(ls,l,m);
	if(m<qr)
		update(rs,m+1,r);
	a[o]=a[ls]+a[rs]+ad[o]*(r-l+1);
}//对指定区间内所有数进行修改 
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,t;
	cin>>n>>t;
	for(int i=1;i<=n;i++)
		cin>>temp[i];
	build(1,1,n);
	while(t--)
	{
		int s;
		cin>>s;
		if(s==2)
		{
			cin>>ql>>qr;
			cout<<query(1,1,n,0)<<endl;
		}
		else if(s==1)
		{
			cin>>ql>>qr>>x;
			update(1,1,n);
		}
	}
	return 0;
}
