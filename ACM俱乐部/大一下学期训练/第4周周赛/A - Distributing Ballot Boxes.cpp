#include <cstdio>
#include <iostream>
using namespace std;
int n,b,a[500005];
bool check(int m)
{
	int tot=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]%m)
			tot+=a[i]/m+1;
		else
			tot+=a[i]/m;
	}
	if(tot>b)
		return 1;
	else
		return 0;
}
int main()
{
	ios::sync_with_stdio(false);
	while(cin>>n>>b)
	{
		if(n==-1&&b==-1) break;
		int maxx=0;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			if(a[i]>maxx) maxx=a[i];
		}
		if(n==b)
			cout<<maxx<<endl;
		else
		{
			int l=1,r=maxx,mid;
			while(l<r)
			{
				mid=(l+r)/2;
				if(check(mid)) l=mid+1;
				else r=mid;
			}
			cout<<r<<endl;
		}
	}
	return 0;
}
