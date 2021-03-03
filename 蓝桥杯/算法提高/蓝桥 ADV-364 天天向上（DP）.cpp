#include <iostream>
#include <cstdio> 
using namespace std;
long long dp[2005][2005];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);//不加上只有90分 
	int n,a[2005];
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	long long ans=0;
	for(int i=n-1;i>=0;i--)
	{
		dp[i][1]=1;
		for(int j=i+1;j<n;j++)
		{
			if(a[j]>a[i])
			{
				int k=2;
				while(1)
				{
					if(dp[j][k-1]==0) break;
					dp[i][k]+=dp[j][k-1];
					k++;
				}
			}
		}
	}
	for(int i=0;i<n;i++)
		ans+=dp[i][4];
	cout<<ans<<endl;
	return 0;
}
