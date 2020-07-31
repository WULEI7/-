#include <iostream>
#include <queue>
#include <cstring> 
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,x,y,s[205],vis[205];
	while(cin>>n)
	{
		if(n==0) break;
		cin>>x>>y;
		for(int i=1;i<=n;i++)
			cin>>s[i];
		queue <int> q;
		q.push(x);
		memset(vis,0,sizeof(vis));//注意初始化 
		vis[x]=1;//这里默认起始层和目的层不是同一层 
		while(!q.empty())
		{
			int temp=q.front();
			q.pop();
			if(temp-s[temp]>=1&&!vis[temp-s[temp]])//不能到小于1层 
			{
				q.push(temp-s[temp]);
				vis[temp-s[temp]]=vis[temp]+1;
			}
			if(temp+s[temp]<=n&&!vis[temp+s[temp]])//不能到大于n层 
			{
				q.push(temp+s[temp]);
				vis[temp+s[temp]]=vis[temp]+1;
			}
		}
		cout<<vis[y]-1<<endl;//如果到达目的层，则输出最少的步数；不能到达则输出-1 
	}
	return 0;
}
