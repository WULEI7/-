#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int n,t=0,ans=1;
	cin>>n;
	for(int i=2;i<=n;i++)
	{
		ans+=t;
		t=ans-t;
		ans%=10007;
	}
	cout<<ans<<endl;
	return 0;
}
