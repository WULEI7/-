#include <iostream>
#include <cstdio>
using namespace std;
long long a[100005];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		int ans=0;
		long long temp=1;
		for(int i=2;i<=n;i++)
		{
			if(a[i]>=a[i-1]) continue;
			ans++;
			while(a[i]+temp<a[i-1])
			{
				temp*=2;
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
