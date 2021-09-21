#include <iostream>
#include <cstdio>
#include <set>
using namespace std;
bool vis[100005];
set<pair<int,int>> st;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m,a,b,ans=0;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		cin>>a>>b;
		st.insert({a,b});
		st.insert({b,a});
	}
	for(int i=1;i<n;i++)
	{
		if(vis[i]) continue;
		for(int j=i+1;j<=n;j++)
		{
			if(!vis[j]&&!st.count({i,j}))
			{
				vis[j]=1;
				ans++;
				break;
			}
		}
	}
	cout<<ans<<endl;
	return 0; 
}
