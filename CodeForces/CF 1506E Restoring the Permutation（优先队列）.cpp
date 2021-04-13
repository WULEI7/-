#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
int a[200005],vis[200005],minn[200005],maxn[200005];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		memset(vis,0,sizeof(vis));
		memset(minn,0,sizeof(minn));
		memset(maxn,0,sizeof(maxn));
		priority_queue<int> q1;//´ó¶¥¶Ñ 
		//priority_queue<int,vector<int>,less<int> > q;
		priority_queue<int,vector<int>,greater<int> > q2;//Ð¡¶¥¶Ñ 
		for(int i=1;i<=n;i++)
		{
			if(a[i]!=a[i-1])
			{
				minn[i]=maxn[i]=a[i];
				vis[a[i]]=1;
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(vis[i]==0)
				q2.push(i);
		}
		for(int i=1;i<=n;i++)
		{
			if(minn[i]==0)
			{
				minn[i]=q2.top();
				q2.pop();
			}
		}
		int t1=0,t2=maxn[1];
		for(int i=t1+1;i<t2;i++)
			q1.push(i);
		t1=t2;
		for(int i=2;i<=n;i++)
		{
			if(maxn[i]>0)
			{
				t2=maxn[i];
				for(int j=t1+1;j<t2;j++)
					q1.push(j);
				t1=t2;
			}
			else
			{
				maxn[i]=q1.top();
				q1.pop();
			}
		}
		for(int i=1;i<=n;i++)
			printf("%d ",minn[i]);
		printf("\n");
		for(int i=1;i<=n;i++)
			printf("%d ",maxn[i]);
		printf("\n");
	}
	return 0;
}
