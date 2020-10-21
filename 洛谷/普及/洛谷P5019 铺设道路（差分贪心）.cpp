#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,a,pre=0,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		if(a>pre)
			ans+=a-pre;
		pre=a;
	}
	cout<<ans<<endl;
	return 0;
}
