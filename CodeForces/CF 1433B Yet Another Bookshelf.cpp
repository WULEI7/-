#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t,n,a[55];
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		int ans=0,l,r;
		for(int i=1;i<=n;i++)
			if(a[i]==1)
			{
				l=i;
				break;
			}
		for(int i=n;i>=1;i--)
			if(a[i]==1)
			{
				r=i;
				break;
			}
		for(int i=l;i<=r;i++)
			if(a[i]==0)
				ans++;
		cout<<ans<<endl;
	}
	return 0;
}
