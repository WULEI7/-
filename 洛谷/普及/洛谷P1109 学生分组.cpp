#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,l,r,tot=0,cnt1=0,cnt2=0,a[55];
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		tot+=a[i];
	}
	cin>>l>>r;
	sort(a,a+n);
	if(tot<n*l||tot>n*r)
		printf("-1\n");
	else
	{
		for(int i=0;i<n;i++)
		{
			if(a[i]<l)
				cnt1+=l-a[i];
			if(a[i]>r)
				cnt2+=a[i]-r;
		}
		int cnt=max(cnt1,cnt2);
		printf("%d\n",cnt);
	}
	return 0;
}
