#include <stdio.h>
void change(double n)
{
	int zheng0,c,e=1,zheng=0,pd=0;
	double xiao0;
	zheng0=(int)n;
	xiao0=n-zheng0;
	while(zheng0!=0)
	{
		c=zheng0%2;zheng0/=2;
		zheng+=c*e;
		e*=10;
	}
	printf("%d",zheng);
	if(xiao0!=0) printf(".");
	while((xiao0-pd)!=0)
	{
		xiao0*=2;
		pd=(int)xiao0;
		xiao0-=pd;
		if(xiao0-pd==0) break;
		printf("%d",pd);
	}
}
int main()
{
	double n;
	scanf("%lf",&n);
	change(n);
	return 0;
}
