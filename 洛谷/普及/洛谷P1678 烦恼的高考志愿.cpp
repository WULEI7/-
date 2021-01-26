#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int m,n,b,a[100005],ans=0;
	cin>>m>>n;
	for(int i=0;i<m;i++)
		cin>>a[i];
	sort(a,a+m);
	while(n--)
	{
		cin>>b;
		int t=lower_bound(a,a+m,b)-a;
		if(t==0)
			ans+=abs(a[0]-b);
		else if(t==m)
			ans+=abs(a[m-1]-b);
		else
			ans+=min(abs(a[t-1]-b),abs(a[t]-b));
	}
	cout<<ans<<endl;
	return 0;
}
