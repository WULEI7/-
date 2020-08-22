#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
	int r,y,g,n,k,t,ans=0;
	cin>>r>>y>>g>>n;
	while(n--)
	{
		cin>>k>>t;
		if(k==0||k==1)
			ans+=t;
		else if(k==2)
			ans+=t+r;
	}
	cout<<ans<<endl;
	return 0;
}
