#include <iostream>
#include <cstdio>
using namespace std;
int n,m,k,a,b,ans=0,mp[105][105];
int hbx[13]={-2,-1,-1,-1,0,0,0,0,0,1,1,1,2};
int hby[13]={0,-1,0,1,-2,-1,0,1,2,-1,0,1,0};
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	while(m--)
	{
		cin>>a>>b;
		for(int i=0;i<13;i++)
			if(a+hbx[i]>=1&&a+hbx[i]<=n&&b+hby[i]>=1&&b+hby[i]<=n)
				mp[a+hbx[i]][b+hby[i]]=1;
	}
	while(k--)
	{
		cin>>a>>b;
		for(int i=-2;i<=2;i++)
		for(int j=-2;j<=2;j++)
			if(a+i>=1&&a+i<=n&&b+j>=1&&b+j<=n)
				mp[a+i][b+j]=1;
	}
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
		if(mp[i][j]==0)
			ans++;
	cout<<ans<<endl;
	return 0;
}
