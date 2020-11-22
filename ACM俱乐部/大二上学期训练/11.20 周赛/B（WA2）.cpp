#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
long long a[200005];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		long long sum=0;
		for(int i=0;i<n;i++)
			cin>>a[i];
		sort(a,a+n);
		for(int i=1;i<n-1;i++)
			sum+=a[i];
		long long ans=(n-2)*a[n-1]-sum-a[0];
		if(ans<0)
			ans=ans+n-1;
		cout<<ans<<endl;
	}
	return 0;
}
