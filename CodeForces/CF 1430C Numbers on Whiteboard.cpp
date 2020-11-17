#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	priority_queue<int,vector<int>,less<int> > q;
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		while(!q.empty())
			q.pop();
		for(int i=1;i<=n;i++)
			q.push(i);
		printf("2\n");
		while(q.size()>1)
		{
			int r=q.top();
			q.pop();
			int s=q.top();
			q.pop();
			printf("%d %d\n",r,s);
			q.push((r+s+1)/2);
		}
	}
	return 0;
}
