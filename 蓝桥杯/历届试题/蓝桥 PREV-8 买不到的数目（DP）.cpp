#include <iostream>
#include <cstdio>
using namespace std;
int dp[1000005];
int main()
{
	int a,b;
	cin>>a>>b;
	if(a>b)
	{
		a=a^b;
		b=a^b;
		a=a^b;
	}
	dp[0]=dp[a]=dp[b]=1;
	for(int i=a;i<1000001;i++)
		dp[i]+=dp[i-a];
	for(int i=b;i<1000001;i++)
		dp[i]+=dp[i-b];
	int ans=0;
	for(int i=0;i<1000001;i++)
		if(dp[i]==0)
			ans=i;
	cout<<ans<<endl;
	return 0;
}
