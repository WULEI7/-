#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	long long n,p,a[3];
	cin>>n;
	while(n--)
	{
		cin>>p>>a[0]>>a[1]>>a[2];
		long long ans=1e18;
		for(int i=0;i<3;i++)
		{
			if(p%a[i]==0)
			{
				ans=0;
				break;
			}
			long long t=a[i]-p%a[i];
			if(t<ans) ans=t;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
