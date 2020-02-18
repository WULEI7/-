#include <bits/stdc++.h>
using namespace std;
int main()
{
	int m,n,i,j,ans[10]={0};
	cin >> m >> n;
	for(i=m;i<=n;i++)
	{
		j=i;
		while(j)
		{
			ans[j%10]++;
			j/=10;
		}
	}
	for(i=0;i<10;i++)
		printf("%d ",ans[i]);
	return 0;
}
