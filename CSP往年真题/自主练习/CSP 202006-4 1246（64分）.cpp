#include <bits/stdc++.h>
using namespace std;
map<string,int> mp;
int dp[100005][15];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	mp["1"]=1;mp["2"]=2;mp["4"]=3;mp["6"]=4;
	mp["16"]=5;mp["26"]=6;mp["41"]=7;mp["44"]=8;mp["46"]=9;
	mp["61"]=10;mp["62"]=11;mp["64"]=12;mp["66"]=13;mp["42"]=14;
	int n,k;
	string s;
	cin>>n;
	cin>>s;
	k=mp[s];
	dp[0][1]=1;
	for(int i=1;i<=n;i++)
	{
		dp[i][1]+=dp[i-1][3];
		dp[i][2]+=dp[i-1][1];
		dp[i][3]+=dp[i-1][2]+dp[i-1][4];
		dp[i][4]+=dp[i-1][3]+dp[i-1][4];
		dp[i][5]+=dp[i-1][3];
		dp[i][6]+=dp[i-1][5];
		dp[i][7]+=dp[i-1][12];
		dp[i][8]+=dp[i-1][11];
		dp[i][9]+=dp[i-1][6]+dp[i-1][13];
		dp[i][10]+=dp[i-1][8];
		dp[i][11]+=dp[i-1][7];
		dp[i][12]+=dp[i-1][4]+dp[i-1][14];
		dp[i][13]+=dp[i-1][9];
		dp[i][14]+=dp[i-1][10];
		for(int j=1;j<=14;j++)
			dp[i][j]%=998244353;
	}
	printf("%d\n",dp[n][k]);
}
