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
		long long sum=0,ans=0;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			sum+=a[i];
		}
		sort(a,a+n);
		for(int i=1;i<n-1;i++)
			if(a[n-1]-a[i]>1)
				ans+=a[n-1]-a[i]-1;
		sum+=ans;
		if(sum%(n-1)>0)
			ans+=n-1-sum%(n-1);
		cout<<ans<<endl;
	}
	return 0;
}
