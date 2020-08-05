#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	long long n,m;
	while(cin>>n>>m)
	{
		long long a=2016,b=2016,ans=0;
		if(n<2016) a=n;
		if(m<2016) b=m;
		for(int i=1;i<=a;i++)
		for(int j=1;j<=b;j++)
			if(i*j%2016==0)
				ans+=((n-i)/2016+1)*((m-j)/2016+1);
		cout<<ans<<endl;
	}
	return 0;
}
