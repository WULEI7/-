#include <iostream>
#include <cstdio>
using namespace std;
bool dp[5005][5005];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0); 
	for(int i=0;i<=5000;i++)
	for(int j=0;j<=5000;j++)
	{
		if(dp[i][j]==false)
		{
			for(int k=1;i+k<=5000;k++)
			for(int s=0;j+s*k<=5000;s++)
				dp[i+k][j+s*k]=true;
			for(int k=1;j+k<=5000;k++)
			for(int s=0;i+s*k<=5000;s++)
				dp[i+s*k][j+k]=true;
		}
	}
	int t,n,m;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		if(dp[n][m]==1)
			cout<<"Alice"<<endl;
		else
			cout<<"Bob"<<endl;
	}
	return 0;
}
