#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
vector<int> g[12];
int ans=0,vis[12];
void dfs(int t)
{
	ans++;
	for(int i=0;i<g[t].size();i++)
		if(!vis[g[t][i]])
		{
			vis[g[t][i]]=1;
			dfs(g[t][i]);
		}
}
int main()
{
	g[0].push_back(6);
	g[0].push_back(8);
	g[0].push_back(11);
	g[7].push_back(0);
	g[9].push_back(0);
	g[10].push_back(0);
	
	g[1].push_back(6);
	g[1].push_back(7);
	g[1].push_back(8);
	g[1].push_back(11);
	g[9].push_back(1);
	g[10].push_back(1);
	
	g[2].push_back(6);
	g[2].push_back(7);
	g[2].push_back(8);
	g[2].push_back(11);
	
	g[3].push_back(6);
	g[3].push_back(7);
	g[3].push_back(8);
	g[3].push_back(11);
	
	g[6].push_back(4);
	g[7].push_back(4);
	g[9].push_back(4);
	g[10].push_back(4);
	g[4].push_back(8);
	g[8].push_back(4);
	
	g[6].push_back(5);
	g[7].push_back(5);
	g[9].push_back(5);
	g[10].push_back(5);
	g[5].push_back(11);
	g[11].push_back(5);
	
	for(int i=0;i<12;i++)
	{
		memset(vis,0,sizeof(vis));
		ans=0;
		vis[i]=1;
		dfs(i);
		if(i<6)
			cout<<"f";
		else
			cout<<"g";
		cout<<i%6+1<<"µÄÖµÎª";
		cout<<ans<<endl;
	}
	return 0;
}
