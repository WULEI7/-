#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;
	double t;
	priority_queue<double,vector<double>,greater<double>> q;
	cin>>n;
	while(n--)
	{
		cin>>t;
		q.push(t);
	}
	while(q.size()>1)
	{
		double a=q.top();
		q.pop();
		double b=q.top();
		q.pop();
		q.push((a+b)/2);
	}
	cout<<(int)q.top()<<endl;
	return 0;
}
