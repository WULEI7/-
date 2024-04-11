#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn=1010;
vector<int> G[maxn];//邻接表 
int n,m,k,a,b,c,p[maxn],vis[maxn];
int find(int x)
{
	return p[x]==x?x:p[x]=find(p[x]);
}//并查集 
void unio(int a,int b)
{
	int x=find(a),y=find(b);
	if(x!=y) p[x]=y;
}
void init()
{
	for(int i=1;i<=n;i++)
	{
		p[i]=i;
		vis[i]=0;
	}
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++)
	{
		cin>>a>>b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	for(int t=0;t<k;t++)
	{
		cin>>c;
		init();
		for(int i=1;i<=n;i++)
		{
			int size=G[i].size();
			for(int j=0;j<size;j++)
			{
				if(i!=c&&G[i][j]!=c)
					unio(i,G[i][j]);
			}
		}
		int ans=0;
		/* 
		for(int i=1;i<=n;i++)
			if(i!=c) find(i);//注意是find(i)不是p[i] 
		sort(p+1,p+n+1);
		for(int i=1;i<=n;i++)
			if(p[i]!=p[i-1]&&p[i]!=c)
				ans++;
		cout<<ans-1<<endl;
		*/
		for(int i=1;i<=n;i++)
		{
			if(i==c) continue;
			int fa=find(i);
			if(!vis[fa])
			{
				ans++;
				vis[fa]=1;
			}
		}
		cout<<ans-1<<endl;
	}
	return 0;
}
