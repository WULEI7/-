#include <iostream>
#include <cstdio>
using namespace std;
int ishuiwen(int n,int k)
{
	int a=n,b=0,t=0;
	while(a!=0)
	{
		t+=a%10;
		b=b*10+a%10;
		a=a/10;
		}
	if(n==b&&t==k) return 1;
	return 0;
}
int main()
{
	int k;
	cin>>k;
	for(int i=10000;i<=999999;i++)
		if(ishuiwen(i,k))
			printf("%d\n",i);
	return 0;
}
