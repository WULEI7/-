#include <iostream>
#include <cstdio>
using namespace std;
double num[2][1001],ans[2001];
int main()
{
	int k,n;
	double t;
	for(int i=0;i<=1;i++)
	{
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>n>>t;
			num[i][n]+=t;
		}
	}
	for(int i=0;i<=1000;i++)
		if(num[0][i]!=0.0)
			for(int j=0;j<=1000;j++)
				if(num[1][j]!=0.0)
					ans[i+j]+=num[0][i]*num[1][j];
	int cnt=0;
	for(int i=0;i<=2000;i++)
		if(ans[i]!=0.0)
			cnt++;
	printf("%d",cnt);
	for(int i=2000;i>=0;i--)
		if(ans[i]!=0.0)
			printf(" %d %.1f",i,ans[i]);
	return 0;
}
