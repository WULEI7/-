#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring> 
#include <algorithm>
int b[505],a[505],c[505];
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t,n,k;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		for(int i=0;i<n;i++)
			cin>>b[i];
		sort(b,b+n);
		int cnt=1;
		memset(a,0,sizeof(a));
		a[b[0]]=1;
		for(int i=1;i<n;i++)
		{
			if(b[i]!=b[i-1])
			{
				a[b[i]]=1;
				cnt++;
			}
		}
		if(cnt>k)
		{
			printf("-1\n");
			continue;
		}
		for(int i=1;cnt<k;i++)
		{
			if(a[i]==0)
			{
				a[i]=1;
				cnt++;
			}
		}
		int temp=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==1)
				c[++temp]=i;
		}
		printf("%d\n",n*k);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=k;j++)
				printf("%d ",c[j]);
		printf("\n");
	}
	return 0;
}
