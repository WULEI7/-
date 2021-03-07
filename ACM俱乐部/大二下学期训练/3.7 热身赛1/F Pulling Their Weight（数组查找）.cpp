#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n,tot=0,a[100005],sum[100005],cnt[20005];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		cnt[a[i]]++;
		tot+=a[i];
	}
	sort(a,a+n);
	sum[0]=a[0];
	for(int i=1;i<n;i++)
		sum[i]=sum[i-1]+a[i];//Ç°×ººÍ 
	int ans;
	for(int t=1;t<=20000;t++)
	{
		int pos=lower_bound(a,a+n,t)-a;
		if(sum[pos-1]==tot-sum[pos-1]-cnt[t]*t)
		{
			ans=t;
			break;
		}
	}
	cout<<ans<<endl;
	return 0;
}
