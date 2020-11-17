#include <iostream>
#include <cstdio>
#include <cmath>
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
			if(min(a,b)>=m)
				printf("Yes\n");
			else
				printf("No\n");
		}
	}
	return 0;
}
