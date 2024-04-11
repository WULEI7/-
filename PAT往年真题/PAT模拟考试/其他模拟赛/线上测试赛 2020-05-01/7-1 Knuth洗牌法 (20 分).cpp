#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n,t,a[1005];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		a[i]=i;
	for(int i=1;i<=n;i++)
	{
		cin>>t;
		swap(a[t],a[i]);
	}
	cout<<a[1];
	for(int i=2;i<=n;i++)
		cout<<" "<<a[i];
	return 0;
}
