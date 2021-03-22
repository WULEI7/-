#include <iostream>
#include <cstdio>
using namespace std;
double a[1000005],fpre[1000005],fsuf[1000005];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		fpre[i]=fpre[i-1]+a[i];
		fsuf[n+1-i]=fsuf[n+2-i]+a[n+1-i];
	}//分别计算前后缀和 
	for(int i=1;i<=n;i++)
	{
		fpre[i]/=i;
		fsuf[n+1-i]/=i;
	}//前后缀和分别除以牌的数量 
	double ans=0;//答案最小是0 
	for(int i=1;i<=n;i++)
	{
		if(fpre[i]>ans)
			ans=fpre[i];
		if(fsuf[n+1-i]>ans)
			ans=fsuf[n+1-i];
	}
	printf("%.9f\n",ans);
	return 0;
}
