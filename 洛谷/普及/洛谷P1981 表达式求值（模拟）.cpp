#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	long long n,temp,ans=0;
	char t;
	scanf("%lld",&temp);
	while(scanf("%c",&t))
	{
		if(t=='\n') break;
		scanf("%lld",&n);
		if(t=='*')
			temp=temp*n%10000;
		else if(t=='+')
		{
			ans+=temp;
			ans%=10000;
			temp=n;
		}
	}
	ans+=temp;
	ans%=10000;
	cout<<ans<<endl;
	return 0;
}
