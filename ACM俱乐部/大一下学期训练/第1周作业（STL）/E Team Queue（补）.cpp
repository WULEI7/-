#include <iostream>
#include <cstdio>
#include <queue>
#include <map> 
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t,n,x,k=1;
	string s;
	while(cin>>t)
	{
		if(t==0) break;
		int flag[1005]={0};
		queue<int> tot;
		queue<int> q[1005];
		map<int,int> mp;
		printf("Scenario #%d\n",k++);
		for(int T=1;T<=t;T++)
		{
			cin>>n;
			for(int i=1;i<=n;i++)
			{
				cin>>x;
				mp[x]=T;
			}
		}
		while(cin>>s)
		{
			if(s=="STOP") break;
			if(s=="ENQUEUE")
			{
				cin>>x;
				int group=mp[x];
				if(flag[group]==0)
				{
					flag[group]=1;
					tot.push(group);
				}
				q[group].push(x);
			}
			if(s=="DEQUEUE")
			{
				int group=tot.front();
				int temp=q[group].front();
				printf("%d\n",temp);
				q[group].pop();
				if(q[group].empty())
				{
					tot.pop();
					flag[group]=0;
				}
			}
		}
		printf("\n");
	}
	return 0;
}
