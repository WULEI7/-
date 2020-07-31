#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
struct team
{
	int p,t;
}a[55];
bool cmp(team x,team y)
{
	if(x.p>y.p)
		return true;
	else if(x.p==y.p)
		return x.t<y.t;
	else
		return false;
}
int main()
{
	ios::sync_with_stdio(false);
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++)
		cin>>a[i].p>>a[i].t;
	sort(a,a+n,cmp);
	int p1=a[k-1].p,t1=a[k-1].t,ans=0;
	for(int i=0;i<n;i++)
		if(a[i].p==p1&&a[i].t==t1)
			ans++;
	cout<<ans<<endl;
	return 0;
}
