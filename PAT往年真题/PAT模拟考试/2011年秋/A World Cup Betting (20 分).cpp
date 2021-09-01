#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	double a,b,c,odds=1;
	for(int i=1;i<=3;i++)
	{
		scanf("%lf%lf%lf",&a,&b,&c);
		if(a>b&&a>c)
		{
			printf("W ");
			odds*=a;
		}
		else if(b>a&&b>c)
		{
			printf("T ");
			odds*=b;
		}
		else if(c>a&&c>b)
		{
			printf("L ");
			odds*=c;
		}
	}
	printf("%.2f\n",(odds*0.65-1)*2);
	return 0;
}
