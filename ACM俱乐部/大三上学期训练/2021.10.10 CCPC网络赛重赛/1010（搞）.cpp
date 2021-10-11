#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int t,n,m,x,y,a[1005],b[1005];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--)
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		cin>>n>>m;
		for(int i=0;i<m;i++)
		{
			cin>>x>>y;
			a[x]=b[y]=1;
		}
		cout<<n*n-m<<endl;
		for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			if(a[i]==0||b[j]==0)
				cout<<i<<" "<<j<<endl;
		}
	}
	return 0;
}
