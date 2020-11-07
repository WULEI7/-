#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t,a,b;
	cin>>t;
	while(t--)
	{
		cin>>a>>b;
		if(a==1||b==1||a==2&&b==2)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
