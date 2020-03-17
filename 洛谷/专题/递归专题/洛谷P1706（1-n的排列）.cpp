#include <bits/stdc++.h>
using namespace std;
int n,a[10];
void shuchu(int cur)
{
	int i,j,ok;
	if(cur==n)
	{
		for(i=0;i<n;i++)
			printf("%5d",a[i]);
		printf("\n");
	}
	else
	for(i=1;i<=n;i++)
	{
		ok=1;
		for(j=0;j<cur;j++)
			if(a[j]==i) ok=0;
		if(ok)
		{
			a[cur]=i;
			shuchu(cur+1);
		}
	}
}
int main()
{
	scanf("%d",&n);
	shuchu(0);
	return 0;
}
