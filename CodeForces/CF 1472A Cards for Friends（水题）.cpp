#include <iostream>
#include <cstdio>
using namespace std;
int pow(int x,int n)
{
	int base=x,res=1;
	while(n>0)
	{
		if(n&1)
			res*=base;
		n>>=1;
		base*=base;
	}
	return res;
}
int main()
{
	int t,n,a,b,c;
	cin>>t;
	while(t--)
	{
		cin>>a>>b>>c;
		int x=0,y=0;
		while(a%2==0)
		{
			a/=2;
			x++;
		}
		while(b%2==0)
		{
			b/=2;
			y++;
		}
		n=pow(2,x+y);
		if(n>=c)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
