#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int a[2005][2005];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m,ans=2000000000;
	cin>>m>>n;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
		cin>>a[i][j];
	for(int j=m-1;j>=1;j--)
	for(int i=1;i<=n;i++)
		a[i][j]+=min(a[i][j+1],a[i%n+1][j+1]);
	for(int i=1;i<=n;i++)
		ans=min(ans,a[i][1]);
	cout<<ans<<endl;
	return 0;
}
