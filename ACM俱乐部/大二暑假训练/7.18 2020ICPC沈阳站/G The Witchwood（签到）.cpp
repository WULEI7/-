#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	long long n,k,a[1005],ans=0;
	cin>>n>>k;
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	for(int i=n-1;i>=n-k;i--)
		ans+=a[i];
	cout<<ans<<endl;
	return 0;
}
