#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
const int MAXN=200005;
priority_queue<int,vector<int>,greater<int> > q1;
priority_queue<int,vector<int>,less<int> > q2;
int a[MAXN],u[MAXN];
int main()
{
	ios::sync_with_stdio(false);
	int m,n;
	cin>>m>>n;
	for(int i=1;i<=m;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>u[i];
	int p=0;
	for(int i=1;i<=n;i++)
	{
		while(p<u[i])
		{
			p++;
			q2.push(a[p]);
			q1.push(q2.top());
			q2.pop();
		}
		cout<<q1.top()<<endl;
		q2.push(q1.top());
		q1.pop();
	}
	return 0;
}
