#include <iostream>
#include <cstdio>
using namespace std;
int cnt[205]; 
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,t,maxn=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>t;
		cnt[t]++;
		if(t>maxn) maxn=t;
	}
	int flag=1;
	for(int i=1;i<=maxn;i++)
	{
		if(cnt[i]==0)
		{
			printf("%d\n",i);
			flag=0;
		}
	}
	if(flag==1)
		printf("good job\n");
	return 0;
}
