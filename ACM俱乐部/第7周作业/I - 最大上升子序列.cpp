#include <iostream>
using namespace std;
int main()
{
	int n,num[1005],dp[1005],ans=1;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>num[i];
		dp[i]=1;
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<i;j++)
			if(num[i]>num[j])
				if(dp[j]+1>dp[i])
					dp[i]=dp[j]+1;
	for(int i=0;i<n;i++)
		if(dp[i]>ans)
			ans=dp[i];
	cout<<ans<<endl;
	return 0;
}
