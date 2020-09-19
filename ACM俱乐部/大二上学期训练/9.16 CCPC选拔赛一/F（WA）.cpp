#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
int n,m,vis[55]={0};
struct node
{
	int ti,gi,ki;
	int to[55]={0};
}dot[55];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	for(int T=1;T<=t;T++)
	{
		cin>>n>>m;
		for(int i=1;i<=n;i++)
		{
			cin>>dot[i].ti>>dot[i].gi>>dot[i].ki;
			memset(dot[i].to,0,sizeof(dot[i].to));
			for(int j=0;j<dot[i].ki;j++)
				cin>>dot[i].to[j];
		}
		int ans=1999999999;
		for(int i=1;i<=n;i++)
		{
			int time=0,value=0;
			memset(vis,0,sizeof(vis));
			queue<int> q;
			q.push(i);
			vis[i]=1;
			while(!q.empty())
			{
				int temp=q.front();
				q.pop();
				vis[temp]=1;
				time+=dot[temp].ti;
				value+=dot[temp].gi;
				if(value>=m) break;
				for(int i=0;dot[temp].to[i]!=0&&!vis[dot[temp].to[i]];i++)
					q.push(dot[temp].to[i]);
			}
			if(value>=m)
				if(time<ans)
					ans=time;
		}
		printf("Case %d: ",T);
		if(ans<1999999999)
			printf("%d\n",ans);
		else
			printf("Poor Magina, you can't save the world all the time!\n");
	}
	return 0;
}
