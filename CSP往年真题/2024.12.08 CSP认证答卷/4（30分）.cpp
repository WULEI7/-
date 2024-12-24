#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
int n,flag=1,a[100005],k[100005],vis[100005];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		cin>>k[i];
	queue<pair<int,int> > q;
	q.push({1,0});
	vis[1]=1;
	while(!q.empty())
	{
		int pos=q.front().first;
		int time=q.front().second;
		q.pop();
		if(pos==n)
		{
			flag=0;
			cout<<time<<endl;
			break;
		}
		for(int i=1;i<=k[pos];i++)
		{
			if(pos+i<=n&&!vis[pos+i-a[pos+i]])
			{
				//cout<<pos+i-a[pos+i]<<endl;
				vis[pos+i-a[pos+i]]=1;
				q.push({pos+i-a[pos+i],time+1});
			}
		}
	}
	if(flag)
		cout<<-1<<endl;
	return 0;
}