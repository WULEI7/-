#include <iostream>
#include <cstdio>
using namespace std;
unsigned long long a[100005],b[100005],c[100005];
unsigned long long Cn4(long long x)
{
	unsigned long long temp=x;
	temp*=x-1;
	temp/=2;
	temp*=x-2;
	temp/=3;
	temp*=x-3;
	temp/=4;
	return temp;
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	/*for(int i=3;i<=100000;i++)
		a[i]=a[i-1]+i-3;
	for(int i=3;i<=100000;i++)
		b[i]=b[i-1]+a[i];
	for(int i=3;i<=100000;i++)
		c[i]=c[i-1]+b[i];
	int n;
	cin>>n;
	cout<<c[n]<<endl;*/
	int n;
	cin>>n;
	cout<<Cn4(n)<<endl;
	return 0;
}
