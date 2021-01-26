#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,t,minn=10005,maxn=-10005,sum=0;
	cin>>n;
	while(n--)
	{
		cin>>t;
		sum+=t;
		if(t<minn) minn=t;
		if(t>maxn) maxn=t;
	}
	printf("%d\n%d\n%d\n",maxn,minn,sum);
	return 0;
}
