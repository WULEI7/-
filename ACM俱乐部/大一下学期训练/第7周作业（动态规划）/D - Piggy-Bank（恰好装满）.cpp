#include <iostream>
using namespace std;
const int MAX=1e9;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t,e,f,v,n,p[505],w[505],dp[10005];
	cin>>t;
	while(t--)
	{
		cin>>e>>f;
		v=f-e;
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>p[i]>>w[i];
		dp[0]=0;
		for(int i=1;i<=v;i++)
			dp[i]=MAX;//将dp数组初始化为无穷大，用来判断是否能够恰好装满 
		for(int i=0;i<n;i++)
			for(int j=w[i];j<=v;j++)
				if(dp[j-w[i]]+p[i]<dp[j])
					dp[j]=dp[j-w[i]]+p[i];
		if(dp[v]<MAX)
			cout<<"The minimum amount of money in the piggy-bank is "<<dp[v]<<"."<<endl;
		else
			cout<<"This is impossible."<<endl;
	}
	return 0;
}
