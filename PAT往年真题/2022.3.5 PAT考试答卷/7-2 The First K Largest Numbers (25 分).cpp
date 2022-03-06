#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
int a[10];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,k,t;
	cin>>n>>k;
	if(k>n) k=n;
	if(n<=5)
	{
		for(int i=0;i<n;i++)
			cin>>a[i];
		sort(a,a+n);
		reverse(a,a+n);
		cout<<a[0];
		for(int i=1;i<k;i++)
			cout<<" "<<a[i];
	}
	else
	{
		priority_queue<int,vector<int>,greater<int>> q;
		for(int i=0;i<5;i++)
		{
			cin>>t;
			q.push(t);
		}
		for(int i=5;i<n;i++)
		{
			cin>>t;
			q.push(t);
			q.pop();
		}
		for(int i=4;i>=0;i--)
		{
			a[i]=q.top();
			q.pop();
		}
		cout<<a[0];
		for(int i=1;i<k;i++)
			cout<<" "<<a[i];
	}
	return 0;
}
