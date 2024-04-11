#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,t,a,ans,maxn=0;
	cin>>n>>t;
	while(n--)
	{
		cin>>a;
		if(a>maxn)
			maxn=a;
	}
	ans=maxn%t?maxn/t+1:maxn/t;
	if(ans<2) ans=2;
	cout<<ans<<endl;
	return 0;
}
