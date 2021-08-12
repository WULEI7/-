#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t,n,a,dp[1005];
	cin>>t;
	while(t--)
	{
		memset(dp,0,sizeof(dp));
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>a;
			dp[a]+=a;
		}
		for(int i=3;i<=1000;i++)
		{
			int t1=dp[i-1];
			int t2=dp[i-2]+dp[i];
			int t3=dp[i-3]+dp[i];
			int t=max(t1,t2);
			t=max(t,t3);
			dp[i]=t;
		}
		cout<<dp[1000]<<endl;
	}
	return 0;
}
