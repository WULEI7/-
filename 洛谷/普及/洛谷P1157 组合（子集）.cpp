#include <bits/stdc++.h>
using namespace std;
int n,k,a[22]={0};
void dfs(int cur)
{ 
	int i;
	if(cur==k)
	{
		for(i=1;i<=k;i++)
			printf("%3d",a[i]);
		printf("\n");
	}
	else
		for(i=a[cur]+1;i<=n;i++)
		{
			a[cur+1]=i;
			dfs(cur+1);
		}
}

int main()
{
	cin >> n >> k;
	dfs(0);
	return 0;
}
