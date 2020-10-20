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
		int t=1,cnt=0;
		while(a<=b)
		{
			if(t<2*(b-a))
			{
				a+=t;
				t++;
				cnt++;
			}
			else break;
		}
		cnt+=2*abs(b-a);
		cout<<cnt<<endl;
	}
	return 0;
}
