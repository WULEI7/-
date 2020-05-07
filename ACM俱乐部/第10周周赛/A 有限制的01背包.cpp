#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
struct item
{
	int p,q,v;
}a[505];
bool cmp(item x,item y)
{
	return x.q-x.p<y.q-y.p;
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m,dp[5005];
	while(cin>>n>>m)
	{
		for(int i=0;i<n;i++)
			cin>>a[i].p>>a[i].q>>a[i].v;
		sort(a,a+n,cmp);
		memset(dp,0,sizeof(dp));
		for(int i=0;i<n;i++)
			for(int j=m;j>=0;j--)
				if(j>=a[i].q)
					if(dp[j-a[i].p]+a[i].v>dp[j])
						dp[j]=dp[j-a[i].p]+a[i].v;
		cout<<dp[m]<<endl;
	}
	return 0;
}
