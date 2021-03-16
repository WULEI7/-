#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
map<int,int> cnt;
int ishuiwen(int n)
{
	int a=n,b=0,t=0;
	while(a!=0)
	{
		t+=a%10;
		b=b*10+a%10;
		a=a/10;
		}
	if(n==b) return 1;
	return 0;
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	for(int i=1;i<=20000;i++)
		if(ishuiwen(i))
			cnt[i]=1;
	int t;
	cin>>t;
	while(t--)
	{
		int cost,tip,tot;
		cin>>cost;
		if(cost%5==0)
			tip=cost/5;
		else
			tip=cost/5+1;
		tot=cost+tip;
		while(1)
		{
			if(cnt[tot]==1)
				break;
			tot++;
		}
		tip=tot-cost;
		printf("Input cost: %d\n",cost);
		printf("%d %d\n\n",tip,tot);
	}
	return 0;
}
