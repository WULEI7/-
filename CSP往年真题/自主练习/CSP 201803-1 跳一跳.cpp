#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
	int n,t=0,ans=0;//t表示当前是连续的第几个2 
	while(cin>>n)
	{
		if(n==0) break;
		if(n==1)
		{
			t=0;
			ans++;
		}
		else
		{
			t++;
			ans+=2*t;
		}
	}
	cout<<ans<<endl;
	return 0;
}
