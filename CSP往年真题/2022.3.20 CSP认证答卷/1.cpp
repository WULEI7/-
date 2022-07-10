#include <iostream>
#include <cstdio>
using namespace std;
int n,k,a,b,ans=0,vis[100005];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	vis[0]=1;
	cin>>n>>k;
	while(k--)
	{
		cin>>a>>b;
		if(!vis[b])
			ans++;
		vis[a]=1;
	}
	cout<<ans<<endl;
	return 0;
}