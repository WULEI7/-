#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n,m=0,ans=0,g[105][105];//顶点数n，边数m 
int p[105];//并查集的父节点 

struct edge
{
	int u,v,w;//边的顶点和权值 
}e[105];

bool cmp(edge a,edge b)//边的权值比较 
{
	return a.w<b.w;
}

int find(int x)//并查集操作 
{
	return p[x]==x ? x:p[x]=find(p[x]);
}

int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
		cin>>g[i][j];
	for(int i=1;i<=n;i++)
	for(int j=i+1;j<=n;j++) 
	{
		if(g[i][j]!=0)
		e[++m]={i,j,g[i][j]};
	}//存入每条边 
	sort(e+1,e+m+1,cmp);//按边的权值排序 
	for(int i=1;i<=n;i++)//并查集父节点初始化 
		p[i]=i;
	for(int i=1;i<=m;i++)//依次考虑每条边 
	{
		int u=e[i].u,v=e[i].v,w=e[i].w;
		int x=find(u);
		int y=find(v);
		if(x!=y)
		{
			cout<<u<<" "<<v<<" "<<w<<endl;//输出加入的边 
			p[x]=y;//合并 
			//ans+=w;
		}
	}
	//cout<<ans<<endl;
	return 0;
}
