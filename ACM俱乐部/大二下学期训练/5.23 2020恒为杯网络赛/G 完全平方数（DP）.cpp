#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,a[100005];
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		a[i]=i;
		for(int j=1;j*j<=i;j++)
			a[i]=min(a[i],a[i-j*j]+1);
	}
	cout<<a[n]<<endl;
	return 0;
}
