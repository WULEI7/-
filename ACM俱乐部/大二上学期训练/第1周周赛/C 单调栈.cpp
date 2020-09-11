#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t,n,a[50005],left[50005],right[50005];
	cin>>t;
	for(int T=1;T<=t;T++)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		stack<int> p;
		for(int i=1;i<=n;i++)
		{
			if(p.empty())
			{
				left[i]=0;
				p.push(i);
			}
			else if(a[i]>a[p.top()])
			{
				while(!p.empty()&&a[i]>a[p.top()])
				{
					left[i]=p.top();
					p.pop();
				}
				p.push(i);
			}
			else if(a[i]<a[p.top()])
			{
				left[i]=0;
				p.push(i);
			}
		}
		stack<int> q;
		for(int i=n;i>=1;i--)
		{
			if(q.empty())
			{
				right[i]=0;
				q.push(i);
			}
			else if(a[i]>a[q.top()])
			{
				while(!q.empty()&&a[i]>a[q.top()])
				{
					right[i]=q.top();
					q.pop();
				}
				q.push(i);
			}
			else if(a[i]<a[q.top()])
			{
				right[i]=0;
				q.push(i);
			}
		}
		printf("Case %d:\n",T);
		for(int i=1;i<=n;i++)
			printf("%d %d\n",left[i],right[i]);
	}
	return 0;
}
