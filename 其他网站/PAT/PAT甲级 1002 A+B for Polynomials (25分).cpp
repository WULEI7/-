#include <iostream>
#include <cstdio>
using namespace std;
double num[1005];
int main()
{
	int k,n;
	double t;
	for(int i=1;i<=2;i++)
	{
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>n>>t;
			num[n]+=t;
		}
	}
	int cnt=0;
	for(int i=0;i<=1000;i++)
		if(num[i]!=0.0)
			cnt++;
	printf("%d",cnt);
	for(int i=1000;i>=0;i--)
		if(num[i]!=0.0)
			printf(" %d %.1f",i,num[i]);
	return 0;
}
