#include <cstdio>
#include <iostream>
#include <algorithm>
const int maxn=1005;
using namespace std;
int n,m,p[maxn];
int find(int x)
{
	return p[x]==x ? x:p[x]=find(p[x]);
}//²¢²é¼¯ 
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	while(cin>>n)
	{
		if(n==0) break;
		cin>>m;
		int ans=n-1,a,b;
		for(int i=1;i<=n;i++)
			p[i]=i;
		for(int i=0;i<m;i++)
		{
			cin>>a>>b;
			int x=find(a);
			int y=find(b);
			if(x!=y)
			{
				p[x]=p[y];
				ans--;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
