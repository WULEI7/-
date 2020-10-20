#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	long long t,a,b;
	cin>>t;
	while(t--)
	{
		cin>>a>>b;
		if(a==b)
		{
			cout<<"0"<<endl;
			continue;
		}
		if(a>b)
		{
			a=a^b;
			b=a^b;
			a=a^b;
		}
		int dis=b-a,ans=0,temp=0;
		while(1)
		{
			temp+=(++ans);
			if(temp-dis>=0&&(temp-dis)%2==0)
				break;
		}
		cout<<ans<<endl;
	}
	return 0;
}
