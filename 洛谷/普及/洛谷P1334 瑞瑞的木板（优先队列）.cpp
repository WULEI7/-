#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	priority_queue<int,vector<int>,greater<int> >q;
	int n,x;
	long long ans=0;
	cin>>n;
	while(n--)
	{
		cin>>x;
		q.push(x);
	}
	while(q.size()>1)
	{
		int t1=q.top();
		q.pop();
		int t2=q.top();
		q.pop();
		ans+=t1+t2;
		q.push(t1+t2);
	}
	cout<<ans<<endl;
	return 0;
}
