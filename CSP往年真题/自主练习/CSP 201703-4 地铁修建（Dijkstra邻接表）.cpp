#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
const int inf=999999999;
using namespace std;
struct node
{
	int v,d;
};//边终点和天数 
vector<vector<node> > map(100005);//图 
typedef pair<int,int> par;//天数和边终点 
priority_queue<par,vector<par>,greater<par> > q;//小根堆 
int vis[100005],dis[100005],n,m;
void Dijkstra(int x)//起点为x 
{
	dis[x]=0;//此句必不可少 
	q.push(par(0,x));
	while(!q.empty())
	{
		par k=q.top();
		q.pop();
		int u=k.second;
		if(vis[u]) continue;
		int size=map[u].size();
		for(int i=0;i<size;i++)
		{
			node t=map[u][i];
			if(dis[t.v]>max(dis[u],t.d))
			{
				dis[t.v]=max(dis[u],t.d);
				q.push(par(dis[t.v],t.v));
			}
		}//注意此题是求最小的最大值 
	}
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<=n;i++)
	{
		vis[i]=0;
		dis[i]=inf;
	}//注意初始化 
	while(m--)
	{
		node n1,n2;
		int a,b,c;
		cin>>a>>b>>c;
		n1.d=n2.d=c;
		n1.v=b,n2.v=a;
		map[a].push_back(n1);
		map[b].push_back(n2);
	}
	Dijkstra(1);
	cout<<dis[n]<<endl;
}
