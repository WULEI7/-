#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
long long a[500005],b[500005],ans=0;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,k;
	cin>>n>>k;
	k=min(n,k);
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<n;i++)
	{
		cin>>b[i];
		ans+=abs(b[i]-a[i]);
		if(a[i]<b[i])
			swap(a[i],b[i]);
	}
	sort(a,a+n);
	sort(b,b+n);
	for(int i=0;i<k;i++)
		if(b[n-1-i]-a[i]>0)
			ans+=2*(b[n-1-i]-a[i]);
	cout<<ans<<endl;
	return 0;
}
