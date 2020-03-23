#include <bits/stdc++.h>
using namespace std;
int isprime(long long n)
{
	for(long long i=2;i*i<=n;i++)
		if(n%i==0) return 0;
	return 1;
}
int main()
{
	long long i,x,y,num;
	int flag=1;
	cin>>x>>y;
	num=y-x;
	if(num==0||num==1)
	{cout<<"N";return 0;}
	if(num==2||num==3)
	{cout<<"Y";return 0;}
	if(isprime(num))
	{cout<<"Y";return 0;}
	for(i=2;i<=sqrt(num);i++)
		if(isprime(i)&&num%i==0)
		{flag=0;cout<<"Y";break;}
	if(flag) cout<<"N";
	return 0;
}
