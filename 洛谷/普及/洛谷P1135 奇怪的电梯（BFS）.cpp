#include <iostream>
#include <cstdio> 
#include <queue>
using namespace std;
int n,x,y,s[205],vis[205];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>x>>y;
	for(int i=1;i<=n;i++)
		cin>>s[i];
	queue<pair<int,int>> q;//BFS的队列 
	q.push({x,0});
	vis[x]=1;//访问起始层 
	while(!q.empty())
	{
		int temp=q.front().first,time=q.front().second;
		q.pop();
		if(temp==y)//到达目的层，输出最小步数 
		{
			cout<<time<<endl;
			return 0;
		}
		if(temp-s[temp]>=1&&!vis[temp-s[temp]])//不能到小于1层 
		{
			q.push({temp-s[temp],time+1});
			vis[temp-s[temp]]=1;
		}
		if(temp+s[temp]<=n&&!vis[temp+s[temp]])//不能到大于n层 
		{
			q.push({temp+s[temp],time+1});
			vis[temp+s[temp]]=1;
		}
	}
	cout<<-1<<endl;//不能到达则输出-1 
	return 0;
}
