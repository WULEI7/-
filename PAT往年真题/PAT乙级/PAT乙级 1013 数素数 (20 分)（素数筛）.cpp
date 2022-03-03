#include <iostream>
#include <cstdio>
using namespace std;
int isprime[200005],prime[100005];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int a,b,cnt=0;
	for(int i=2;i<=200000;i++)
		isprime[i]=1;
	for(int i=2;i<=200000;i++)
	{
		if(isprime[i])
		{
			prime[++cnt]=i;
			for(long long j=(long long)i*i;j<=200000;j+=i)
				isprime[j]=0;
		}
	}
	cin>>a>>b;
	cnt=0;
	for(int i=a;i<=b;i++)
	{
		cnt++;
		if(cnt%10==1)
			cout<<prime[i];
		else
			cout<<" "<<prime[i];
		if(cnt%10==0)
			cout<<endl;
	}
	return 0;
}
