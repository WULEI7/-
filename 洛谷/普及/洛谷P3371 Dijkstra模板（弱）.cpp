#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
const int inf=2147483647;//int范围最大值，此题有一个测试点存在不能达到的情况 
using namespace std;
struct node
{
	int v;
	int d;
};//边终点和长度 
vector<vector<node> > map(100005);//图 
typedef pair<int,int> par;//长度和边终点 
priority_queue<par,vector<par>,greater<par> > q;//小根堆 
int vis[100005],n,m,s;
int dis[100005];
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
			if(dis[t.v]>dis[u]+t.d)
			{
				dis[t.v]=dis[u]+t.d;
				q.push(par(dis[t.v],t.v));
			}
		}//此题求最短路 
	}
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>s;
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
		/*n1.d=n2.d=c;
		n1.v=b,n2.v=a;
		map[a].push_back(n1);
		map[b].push_back(n2);*/
		//注意此题是有向图！
		n1.d=c;
		n1.v=b;
		map[a].push_back(n1); 
	}
	Dijkstra(s);//此题从s点出发 
	printf("%d",dis[1]);
	for(int i=2;i<=n;i++)
		printf(" %d",dis[i]);
	printf("\n");
	return 0;
}
