#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
long long q,k,n;
const long long maxn=100010;
bool is_prime(long long n)
{
	if(n==1) return false;
	long long sqr=(long long)sqrt(1.0*n);
	for(long long i=2;i<=sqr;i++)
		if(n%i==0) return false;
	return true;
}
long long prime[maxn],pnum=0;
void find_prime()
{
	for(long long i=1;i<maxn;i++)
		if(is_prime(i))
			prime[pnum++]=i;
}
struct factor
{
	long long x,cnt;
}fac[10];
int main()
{
	//ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	find_prime();
	cin>>q;
	while(q--)
	{
		cin>>n>>k;
		long long num=0;
		long long sqr=(long long)sqrt(1.0*n);
		for(long long i=0;i<pnum&&prime[i]<=sqr;i++)
		{
			if(n%prime[i]==0)
			{
				fac[num].x=prime[i];
				fac[num].cnt=0;
				while(n%prime[i]==0)
				{
					fac[num].cnt++;
					n/=prime[i];
				}
				num++;
			}
			if(n==1) break;
		}
		if(n!=1)
		{
			fac[num].x=n;
			fac[num++].cnt=1;
		}
		/*
		for(int i=0;i<num;i++)
		{
			if(i>0) printf("*");
			printf("%d",fac[i].x);
			if(fac[i].cnt>1)
				printf("^%d",fac[i].cnt);
		}
		printf("\n");
		*/
		long long ans=1;
		for(long long i=0;i<num;i++)
			if(fac[i].cnt>=k)
			{
				//cout<<fac[i].x<<" "<<fac[i].cnt<<endl;
				ans*=pow(fac[i].x,fac[i].cnt);
			}
		cout<<ans<<endl;
	}
	return 0;
}