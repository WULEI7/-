#include <iostream>
#include <cstdio>
using namespace std;
int n,b[100005];

int check(long long s)
{
	long long t=0;
	for(int i=0;i<n;i++)
		if(b[i]<s)
			t+=s-b[i];
	if(s>=t)
		return 1;
	return 0;
}

int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int T;
	cin>>T;
	for(int k=1;k<=T;k++)
	{
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>b[i];
		long long l=0,r=2e9;
		while(l<r-1)
		{
			long long mid=(l+r)/2;
			if(check(mid)==1)
				l=mid;
			else
				r=mid;
		}
		printf("Case #%d: %lld\n",k,r);
	}
	return 0;
}
