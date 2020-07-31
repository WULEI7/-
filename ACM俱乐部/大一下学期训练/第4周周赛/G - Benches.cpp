#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;
int main()
{
	int n,m,a,maxx=0;
	priority_queue<int,vector<int>,greater<int> > q;
	cin>>n>>m;
	while(n--)
	{
		cin>>a;
		if(a>maxx) maxx=a;
		q.push(a);
	}
	maxx+=m;
	while(m--)
	{
		int temp;
		temp=q.top();
		q.pop();
		temp++;
		q.push(temp);
	}
	while(q.size()>1)
		q.pop();
	cout<<q.top()<<" "<<maxx<<endl;
	return 0;
}
