#include <iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,x[10005],dp[10005],ans;
	while(cin>>n)
	{
		for(int i=0;i<n;i++)
		{
			cin>>x[i];
			dp[i]=1;
		}
		for(int i=1;i<n;i++)
			for(int j=0;j<i;j++)
				if(x[j]<x[i])
					if(dp[j]+1>dp[i])
						dp[i]=dp[j]+1;
		ans=1;
		for(int i=0;i<n;i++)
			if(dp[i]>ans)
				ans=dp[i];
		cout<<ans<<endl;
	}
	return 0;
}
