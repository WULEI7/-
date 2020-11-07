#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
int b[505],a[505];
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
		a[0]=b[0];
		for(int i=1;i<n;i++)
		{
			if(b[i]!=b[i-1])
			{
				a[cnt]=b[i];
				cnt++;
			}
		}
		if(cnt>k)
		{
			printf("-1\n");
			continue;
		}
		printf("%d\n",n*cnt);
		for(int i=1;i<=n;i++)
			for(int j=0;j<=cnt-1;j++)
				printf("%d ",a[j]);
		printf("\n");
	}
	return 0;
}
