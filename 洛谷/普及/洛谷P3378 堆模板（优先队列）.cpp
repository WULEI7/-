#include <iostream>
#include <cstdio>
#include <queue>
using namespace std; 
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t,a,b;
	priority_queue<int,vector<int>,greater<int>> q;
	cin>>t;
	while(t--)
	{
		cin>>a;
		if(a==1)
		{
			cin>>b;
			q.push(b);
		}
		if(a==2)
			cout<<q.top()<<endl;
		if(a==3)
			q.pop();
	}
	return 0;
}
