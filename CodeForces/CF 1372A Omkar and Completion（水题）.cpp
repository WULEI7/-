#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		printf("1");
		for(int i=1;i<n;i++)
			printf(" 1");
		printf("\n");
	}
	return 0;
}
