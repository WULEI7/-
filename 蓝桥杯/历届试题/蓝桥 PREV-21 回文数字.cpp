#include <iostream>
#include <cstdio>
using namespace std;
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
	int sum,cnt=0;
	cin>>sum;
	for(int i=10000;i<=999999;i++)
	{
		int n=i,temp=0;
		if(ishuiwen(n)==0) continue;
		while(n)
		{
			temp+=n%10;
			n/=10;
		}
		if(temp==sum)
		{
			cnt++;
			printf("%d\n",i);
		}
	}
	if(cnt==0)
		printf("-1\n");
	return 0;
} 
