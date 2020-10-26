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
		for(int i=0;i<=n/3;i++)
		for(int j=0;j<=n/5;j++)
		for(int k=0;k<=n/7;k++)
		{
			if(3*i+5*j+7*k==n)
			{
				printf("%d %d %d\n",i,j,k);
				goto label;
			}
		}
		printf("-1\n");
		label:;
	}
	return 0;
}
