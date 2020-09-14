#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
	int n,m,dp[10005],val[105];
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>val[i];
	dp[0]=1;
	for(int i=0;i<n;i++)
		for(int j=m;j>=val[i];j--)
			dp[j]+=dp[j-val[i]];
	cout<<dp[m]<<endl;
	return 0;
}
