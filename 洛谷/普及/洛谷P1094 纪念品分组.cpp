#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int w,n,a[30005];
	cin>>w>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	int l=0,r=n-1,ans=0;
	while(l<r)
	{
		if(a[l]+a[r]<=w)
		{
			l++;
			r--;
		}
		else
			r--;
		ans++;
	}
	if(l==r)
		ans++;
	printf("%d\n",ans);
	return 0;
}
