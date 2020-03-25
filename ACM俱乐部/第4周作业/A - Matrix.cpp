#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
ll t,n,m;
ll fun(ll i,ll j)
{
	return i*i+100000*i+j*j-100000*j+i*j;
}
bool check(ll x)
{
	ll tot=0;
	for(ll i=1;i<=n;i++)
	{
		ll l=1,r=n,mid,temp=0;
		while(l<=r)
		{
			mid=l+(r-l)/2;
			if(fun(mid,i)<=x)
			{
				temp=mid;
				l=mid+1;
			}
			else
				r=mid-1;
		}
		tot+=temp;
		if(tot>=m)
			return true;
	}
	return false;
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		ll l=-100000*n,r=n*n+100000*n+2*n*n,mid,ans;
		while(l<=r)
		{
			mid=l+(r-l)/2;
			if(check(mid))
			{
				ans=mid;
				r=mid-1;
			}
			else
				l=mid+1;
		}
		cout<<ans<<endl;
	}
	return 0;
}
