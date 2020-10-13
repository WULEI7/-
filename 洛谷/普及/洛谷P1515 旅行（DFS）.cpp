#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int a,b,n,ans=0;
int dis[40]={0,990,1010,1970,2030,2940,3060,3930,4060,4970,5030,5990,6010,7000};
void dfs(int x)
{
	if(x==7000)
	{
		ans++;
		return;
	}
	for(int i=1;i<=n+13;i++)
	{
		if(dis[i]>=x+a&&dis[i]<=x+b)
		{
			if(x+a>=7000)
			{
				ans++;
				return;
			}
			dfs(dis[i]);
		}
	}
	return;
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>a>>b>>n;
	for(int i=0;i<n;i++)
		cin>>dis[14+i];
	sort(dis,dis+n+14);
	dfs(0);
	cout<<ans<<endl;
	return 0;
}
