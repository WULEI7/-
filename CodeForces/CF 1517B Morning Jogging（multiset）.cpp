#include <iostream>
#include <cstdio>
#include <set>
#include <cstring>
#include <algorithm>
using namespace std;
int T,m,n,a[105][105],vis[105];
struct node
{
	int v,x,y;
	bool operator < (const node &b) const
	{
		return v<b.v;
	}
};
multiset<node> q;
multiset<node>::iterator it;
void change(int v,int x,int y,int a,int b)
{
	node temp;
	temp.v=v;
	temp.x=a;
	temp.y=b;
	it=q.lower_bound(temp);
	while((*it).x!=x||(*it).y!=y) it++;
	q.erase(it);
	q.insert(temp);
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--)
	{
		memset(vis,0,sizeof(vis));
		q.clear();
		cin>>n>>m;
		for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			cin>>a[i][j];
			node t;
			t.v=a[i][j];
			t.x=i;
			t.y=j;
			q.insert(t);
		}
		int temp=m,begin=0;
		while(temp)
		{
			it=q.begin();
			node cur=*it;
			q.erase(it);
			if(vis[cur.y]==0)
			{
				vis[cur.y]=1;
				temp--;
				continue;
			}
			for(int i=begin;i<m;i++)
			{
				if(vis[i]==1) continue;
				vis[i]=1;
				change(a[cur.x][i],cur.x,i,cur.x,cur.y);
				swap(a[cur.x][i],a[cur.x][cur.y]);
				temp--;
				begin=i+1;
				break;
			}
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
				cout<<a[i][j]<<" ";
			cout<<endl;
		}
	}
	return 0;
}
