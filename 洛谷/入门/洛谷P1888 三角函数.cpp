#include <iostream>
#include <cstdio>
using namespace std;
int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}//շת����������Լ�� 
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int a,b,c,g;
	cin>>a>>b>>c;
	if(a>b)
	{
		a=a^b;
		b=a^b;
		a=a^b;
	}
	if(a>c)
	{
		a=a^c;
		c=a^c;
		a=a^c;
	}
	if(b>c)
	{
		b=b^c;
		c=b^c;
		b=b^c;
	}//λ���㽻����������ֵ 
	g=gcd(a,c);
	a/=g;
	c/=g;
	printf("%d/%d",a,c);
	return 0;
}
