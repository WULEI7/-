#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t,a,b;
	cin>>t;
	while(t--)
	{
		cin>>a>>b;
		int n=abs(a-b);
		if(n%10==0)
			cout<<n/10<<endl;
		else
			cout<<n/10+1<<endl;
	}
	return 0;
}
