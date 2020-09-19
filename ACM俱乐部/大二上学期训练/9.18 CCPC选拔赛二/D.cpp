#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t,a,b,c;
	cin>>t;
	while(t--)
	{
		cin>>a>>b>>c;
		if(b>=a/2+1&&c>=a/2)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
