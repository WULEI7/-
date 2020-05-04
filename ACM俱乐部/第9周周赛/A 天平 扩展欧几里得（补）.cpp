#include <iostream>
#include <cmath> 
using namespace std;
int gcd;
void exgcd(int a,int b,int &x,int &y)
{
	if(b==0)
	{
		x=1;
		y=0;
		gcd=a;
	}
	else
	{
		exgcd(b,a%b,x,y);
		int t=y;
		y=x-(a/b)*y;
		x=t;
	}
}//扩展欧几里得，gcd为a和b的最大公约数 

int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int a,b,c,x,y,x1,y1,x2,y2;
	while(cin>>a>>b>>c)
	{
		if(a==0&&b==0&&c==0) break;
		exgcd(a,b,x,y);
		a/=gcd;b/=gcd;c/=gcd;
		x1=x*c;
		x1=(x1%b+b)%b;//最小正数 
		y1=abs((c-a*x1)/b);
		y2=y*c;
		y2=(y2%a+a)%a;//最小正数 
		x2=abs((c-b*y2)/a);
		if(x2+y2<x1+y1)
		{x1=x2;y1=y2;}
		cout<<x1<<" "<<y1<<endl;
	}
	return 0;
}
