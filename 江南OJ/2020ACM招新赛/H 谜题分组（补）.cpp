#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int a[100005],l[100005],r[100005];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,maxn=0,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxn=max(maxn,a[i]);
		l[i]=maxn;
	}
	maxn=0;
	for(int i=n;i>=1;i--)
	{
		maxn=max(maxn,a[i]);
		r[i]=maxn;
	}
	for(int i=1;i<=n;i++)
		ans=max(ans,abs(l[i]-r[i]));
	cout<<ans<<endl;
	return 0;
}
