#include <bits/stdc++.h>
using namespace std;
#define LL long long
int w[21][21][21];
int main()
{
	int i,j,k;
	LL a,b,c;
	for(i=0;i<=20;i++)
	for(j=0;j<=20;j++)
	for(k=0;k<=20;k++)
		w[i][j][k]=1;
	
	for(i=1;i<=20;i++)
	for(j=1;j<=20;j++)
	for(k=1;k<=20;k++)
	{
		if(i<j&&j<k) w[i][j][k]=w[i][j][k-1]+w[i][j-1][k-1]-w[i][j-1][k];
		else w[i][j][k]=w[i-1][j][k]+w[i-1][j-1][k]+w[i-1][j][k-1]-w[i-1][j-1][k-1];
	}
	
	while(scanf("%lld%lld%lld",&a,&b,&c)==3)
	{
		if(a==-1&&b==-1&c==-1) break;
		else if(a<=0||b<=0||c<=0)
			printf("w(%lld, %lld, %lld) = 1\n",a,b,c);	
		else if(a>20||b>20||c>20)
			printf("w(%lld, %lld, %lld) = %d\n",a,b,c,w[20][20][20]);
		else printf("w(%lld, %lld, %lld) = %d\n",a,b,c,w[a][b][c]);
	}
	return 0;
}
