#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	double a,b,c,ans=1.0;
	for(int i=1;i<=3;i++)
	{
		cin>>a>>b>>c;
		double t=0; 
		if(a>t) t=a;
		if(b>t) t=b;
		if(c>t) t=c;
		if(t==a)
			printf("W ");
		if(t==b)
			printf("T ");
		if(t==c)
			printf("L ");
		ans*=t;
	}
	ans=(ans*0.65-1)*2;
	printf("%.2f\n",ans);
	return 0;
}
