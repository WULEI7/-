#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
struct node
{
	int l,r;
	bool operator < (node y) const
	{
		return r-l==y.r-y.l ? l>y.l : r-l<y.r-y.l;
	}
};
/*bool operator < (node x,node y)
{
	return x.r-x.l==y.r-y.l ? x.l>y.l : x.r-x.l<y.r-y.l;
}*/
int ans[200005];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int T,n;
	cin>>T;
	while(T--)
	{
		cin>>n;
		priority_queue<node> q;
		node a;
		a.l=1;a.r=n;
		q.push(a);
		int cnt=1;
		while(!q.empty())
		{
			node t=q.top();
			q.pop();
			int len=t.r-t.l+1;
			int mid=(t.l+t.r)/2;
			ans[mid]=cnt;
			cnt++;
			if(len==2)
				q.push({t.r,t.r});
			else if(len>2)
			{
				q.push({t.l,mid-1});
				q.push({mid+1,t.r});
			}
		}
		for(int i=1;i<=n;i++)
			printf("%d ",ans[i]);
		printf("\n");
	}
	return 0;
}
