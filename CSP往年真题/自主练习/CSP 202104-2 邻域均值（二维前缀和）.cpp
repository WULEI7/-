#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n,L,r,t,ans=0,a[605][605],sum[605][605];
signed main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>L>>r>>t;
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	{
		cin>>a[i][j];
		sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+a[i][j];//¶þÎ¬Ç°×ººÍ 
	}
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	{
		int up=max(0,i-r);
		int down=min(n-1,i+r);
		int left=max(0,j-r);
		int right=min(n-1,j+r);
		int s=sum[down][right]-sum[down][left-1]-sum[up-1][right]+sum[up-1][left-1];
		int cnt=(down-up+1)*(right-left+1);
		if(s<=t*cnt)
			ans++;
	}
	cout<<ans<<endl;
	return 0;
}
