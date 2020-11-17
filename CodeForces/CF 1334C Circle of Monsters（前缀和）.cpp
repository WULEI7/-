#include <iostream>
#include <cstdio>
using namespace std;
long long a[300005],b[300005],c[300005];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>a[i]>>b[i];
		long long ans=1e18,sum=0;
		for(int i=0;i<n;i++)
		{
			if(i==0)
				c[0]=a[0]-b[n-1];
			else
				c[i]=a[i]-b[i-1];
			if(c[i]<0)
				c[i]=0;
			sum+=c[i];
		}
		for(int i=0;i<n;i++)
			if(sum+a[i]-c[i]<ans)
				ans=sum+a[i]-c[i];
		cout<<ans<<endl;
	}
	return 0;
}
