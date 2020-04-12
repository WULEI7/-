#include <iostream>
#include <algorithm>
using namespace std;
const int MIN=-1e9;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t,n,m,x[22][1002],dp[22][1002];
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				cin>>x[i][j];
		for(int i=0;i<=n;i++)
			dp[i][0]=0;
		for(int j=0;j<=m;j++)
			dp[0][j]=MIN;//因为有负值，所以将左上两边外初始化为无限小 
		dp[0][1]=dp[1][0]=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
			{
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
				for(int k=2;k<=j;k++)
					if(j%k==0)
						if(dp[i][j/k]>dp[i][j])
							dp[i][j]=dp[i][j/k];//选择走到这一点值最大的路径 
				dp[i][j]+=x[i][j];//加上这一点的值 
			}
		cout<<dp[n][m]<<endl;
	}
	return 0;
}
