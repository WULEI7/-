#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int t,n,a[105],b[105],c[105];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i]>>b[i];
		for(int i=1;i<=n;i++)
			cin>>c[i];
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			ans+=c[i]+a[i]-b[i-1];
			if(i<n)
				ans=max(ans+(b[i]-a[i]+1)/2,b[i]);
		}
		cout<<ans<<endl;
	}
	return 0;
}
