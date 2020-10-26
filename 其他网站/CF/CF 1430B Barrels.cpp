#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
long long b[200005];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t,n,k;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		for(int i=0;i<n;i++)
			cin>>b[i];
		sort(b,b+n);
		long long ans=b[n-1];
		for(int i=1;i<=k;i++)
		{
			ans+=b[n-1-i];
			if(i==n-1) break;
		}
		cout<<ans<<endl;
	}
	return 0;
}
