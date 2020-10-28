#include <iostream>
#include <cstdio>
#include <stack>
int a[3000005],t[3000005];
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	stack<int> s;
	for(int i=n;i>=1;i--)
	{
		while(!s.empty()&&a[s.top()]<=a[i])
			s.pop();
		if(!s.empty())
			t[i]=s.top();
		else
			t[i]=0;
		s.push(i);
	}
	for(int i=1;i<=n;i++)
		printf("%d ",t[i]);
	printf("\n");
	return 0;
}
