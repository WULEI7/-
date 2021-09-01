#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;
const double PI=acos(-1.0);
const double EPS=1e-8;
int n,vis[2005];
double x[2005],y[2005],r[2005];
struct node
{
	int a,b;
	double d;
	bool operator < (const node &x) const
	{
		return d>x.d;
	}
};
double dis(int a,int b)
{
	double dx=fabs(x[a]-x[b]);
	double dy=fabs(y[a]-y[b]);
	return sqrt(dx*dx+dy*dy);
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>x[i]>>y[i];
	priority_queue<node> q;
	for(int i=1;i<=n;i++)
	for(int j=i+1;j<=n;j++)
		q.push({i,j,dis(i,j)/2.0});
	while(!q.empty())
	{
		node t=q.top();
		q.pop();
		if(vis[t.a]&&vis[t.b]) continue;
		if(!vis[t.a]&&!vis[t.b])
		{
			vis[t.a]=vis[t.b]=1;
			r[t.a]=r[t.b]=t.d;
			for(int i=1;i<=n;i++)
				if(!vis[i])
				{
					q.push({t.a,i,dis(t.a,i)-t.d});
					q.push({t.b,i,dis(t.b,i)-t.d});
				}
			continue;
		}
		if(vis[t.a]) swap(t.a,t.b);
		if(fabs(t.d+r[t.b]-dis(t.a,t.b))<EPS)//注意double类型千万不能用等号，必须要用EPS 
		{
			vis[t.a]=1;
			r[t.a]=t.d;
			for(int i=1;i<=n;i++)
				if(!vis[i])
					q.push({t.a,i,dis(t.a,i)-t.d});
		}
	}
	double ans=0;
	for(int i=1;i<=n;i++)
		ans+=PI*r[i]*r[i];
	printf("%.15f\n",ans);
	return 0;
}
