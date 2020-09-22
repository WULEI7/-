#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,x,a[505][505]={0},ans=0;
	cin>>n;
	for(int i=1;i<n;i++)
	for(int j=i+1;j<=n;j++)
	{
		cin>>x;
		a[i][j]=a[j][i]=x;
	}
	for(int i=1;i<=n;i++)
	{
		sort(a[i]+1,a[i]+1+n);
		if(a[i][n-1]>ans)
			ans=a[i][n-1];
	}
	printf("1\n%d\n",ans);
	return 0;
}
