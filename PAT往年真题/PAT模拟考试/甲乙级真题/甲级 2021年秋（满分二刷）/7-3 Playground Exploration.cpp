#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
int n,m,a,b,temp=1,start=1,total=0,vis[105];
vector<int> g[105];
void DFS(int pos,int dis)
{
	vis[pos]=1;
	if(dis>total||dis==total&&temp<start)
	{
		start=temp;
		total=dis;
	}
	int size=g[pos].size();
	for(int i=0;i<size;i++)
	{
		if(!vis[g[pos][i]])
		{
			DFS(g[pos][i],dis+1);
			break;
		}
	}
	//注意访问规则 
	//Assume that once a kid starts to explore the playground from any meeting spot, 
	//he/she will always choose the next destination with the smallest number, 
	//and he/she would never want to visit the same spot twice. 
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	while(m--)
	{
		cin>>a>>b;
		g[a].emplace_back(b);
		g[b].emplace_back(a);
	}
	for(int i=1;i<=n;i++)
		sort(g[i].begin(),g[i].end());
	for(int i=1;i<=n;i++)
	{
		memset(vis,0,sizeof(vis));
		temp=i;
		DFS(i,1);
	}
	cout<<start<<" "<<total<<endl;
	return 0;
}
