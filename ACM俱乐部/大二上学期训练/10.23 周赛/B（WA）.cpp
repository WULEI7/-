#include <iostream>
#include <cstdio>
using namespace std;
int u[200005],v[200005],cnt[200005];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>u[i]>>v[i];
		cnt[u[i]]++;
		cnt[v[i]]++;
	}
	int flag=0;
	for(int i=1;i<=n;i++)
	{
		if(cnt[i]==m)
		{
			flag=i;
			break;
		}
	}
	if(flag==0)
		printf("NO\n");
	else
	{
		printf("YES\n");
		for(int i=1;i<=m;i++)
		{
			if(u[i]==flag)
				printf("1");
			else
				printf("0");
		}
		printf("\n");
	}
	return 0;
}
