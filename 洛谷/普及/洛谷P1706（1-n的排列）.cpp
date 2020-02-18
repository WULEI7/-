#include <bits/stdc++.h>
using namespace std;
void shuchu(int n,int a[],int cur)
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
			shuchu(n,a,cur+1);
		}
	}
}
int main()
{
	int n,a[10];
	scanf("%d",&n);
	shuchu(n,a,0);
	return 0;
}
