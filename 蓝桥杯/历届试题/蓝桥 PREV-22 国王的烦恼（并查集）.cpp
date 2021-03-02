#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n,m,p[100005];
struct node
{
	int x,y,t;
}bri[100005];
bool cmp(node a,node b)
{
	return a.t>b.t; 
}
int find(int x)
{
	return p[x]==x?x:p[x]=find(p[x]);
}
int Union(int x,int y)
{
	x=find(x);
	y=find(y);
	if(x!=y)
	{
		p[x]=y;
		return 1;
	}
	return 0;
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		p[i]=i;
	for(int i=0;i<m;i++)
		cin>>bri[i].x>>bri[i].y>>bri[i].t;
	sort(bri,bri+m,cmp);
	int day=-1,ans=0;
	for(int i=0;i<m;i++)
	{
		int check=Union(bri[i].x,bri[i].y);
		if(check==1&&bri[i].t!=day)
		{
			ans++;
			day=bri[i].t;
		}
	}
	cout<<ans<<endl;
	return 0;
}
