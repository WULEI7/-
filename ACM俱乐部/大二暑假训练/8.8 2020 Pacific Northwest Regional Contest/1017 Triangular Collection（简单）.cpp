#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
signed main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,a[55];
	long ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	for(int j=i+1;j<=n;j++)
	{
		int k=j+1;
		while(a[i]+a[j]>a[k]&&k<=n)
			k++;
		ans+=(1L<<(k-j-1))-1;
	}
	cout<<ans<<endl;
	return 0;
}
