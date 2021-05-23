#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
	int t,n,m;
	long long a[1005];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++)
			a[i%m]++;//0µ½m-1 
		long long ans=0;
		if(a[0]>0)
			ans+=(a[0]*(a[0]-1))/2;
		if(m%2==0)
		{
			if(a[m/2]>0)
				ans+=(a[m/2]*(a[m/2]-1))/2;
			for(int i=1;i<m/2;i++)
				ans+=a[i]*a[m-i];
		}
		if(m%2==1)
		{
			for(int i=1;i<=m/2;i++)
				ans+=a[i]*a[m-i];
		}
		cout<<ans<<endl;
	}
	return 0;
}
