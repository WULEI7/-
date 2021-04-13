#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t,n,a[105],vis[105];
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>a[i];
		sort(a,a+n);
		memset(vis,0,sizeof(vis));
		printf("%d",a[0]);
		vis[0]=1;
		for(int i=1;i<n;i++)
		{
			if(a[i]!=a[i-1])
			{
				printf(" %d",a[i]);
				vis[i]=1;
			}
		}
		for(int i=1;i<n;i++)
		{
			if(vis[i]==0)
				printf(" %d",a[i]);
		}
		printf("\n");
	}
	return 0;
}
