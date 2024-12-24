#include <iostream>
#include <cstdio>
using namespace std;
const int maxn=400005;
int n,m,k,t,c,q,ans[maxn];
int getsum(int x)
{
	int sum=0;
	for(int i=x;i<maxn;i+=(-i)&i)
		sum+=ans[i];
	return sum;
}
void update(int x,int v)
{
	for(int i=x;i>0;i-=(-i)&i)
		ans[i]+=v;
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	while(n--)
	{
		cin>>t>>c;
		if(t-k<=0) continue;
		t-=k;
		c-=1;
		if(c>=t) c=t;
		update(t,1);
		update(t-c-1,-1);
		//for(int i=t-c;i<=t;i++)
		//	ans[i]++;
	}
	while(m--)
	{
		cin>>q;
		cout<<getsum(q)<<endl;
	}
	return 0;
}