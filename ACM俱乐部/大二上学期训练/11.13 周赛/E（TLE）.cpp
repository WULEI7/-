#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
int n,b[100005];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int T;
	cin>>T;
	for(int k=1;k<=T;k++)
	{
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>b[i];
		priority_queue<int,vector<int>,greater<int> > q;
		for(int i=0;i<n;i++)
			q.push(b[i]);
		long long temp=0;
		while(1)
		{
			int s=q.top();
			q.pop();
			q.push(s+1);
			temp++;
			if(temp>q.top())
				break;
		}
		printf("Case #%d: %d\n",k,temp);
	}
	return 0;
}
