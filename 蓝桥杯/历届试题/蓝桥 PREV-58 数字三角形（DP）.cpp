#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,a[105][105],ans;
	cin>>n;
	for(int i=0;i<n;i++)
	for(int j=0;j<=i;j++)
		cin>>a[i][j];
	for(int i=1;i<n;i++)
	for(int j=0;j<=i;j++)
	{
		if(j==0)
			a[i][j]+=a[i-1][0];
		else if(j==i)
			a[i][j]+=a[i-1][j-1];
		else
			a[i][j]+=max(a[i-1][j-1],a[i-1][j]);
	}
	if(n%2==1)
		ans=a[n-1][(n-1)/2];
	else
		ans=max(a[n-1][(n-1)/2],a[n-1][(n-1)/2+1]);
	cout<<ans<<endl;
	return 0;
}
