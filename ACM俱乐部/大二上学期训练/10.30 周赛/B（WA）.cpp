#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;
	long long a,b,n,m;
	cin>>t;
	while(t--)
	{
		cin>>a>>b>>n>>m;
		if(a+b<n+m)
			printf("No\n");
		else
		{
			if(a>b&&n>b&&m<a-b||b>a&&m>a&&n<b-a)
				printf("No\n");
			else
				printf("Yes\n");
		}
	}
	return 0;
}
