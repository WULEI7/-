#include <cstdio>
#include <iostream>
#include <cmath>
#define eps 0.001
using namespace std;
double a,b,c,d,x1,x2,x3;
double f(double x)//ԭ���� 
{
	return a*x*x*x+b*x*x+c*x+d;
}
double fd(double x)//ԭ������ 
{
	return 3*a*x*x+2*b*x+c;
}
double Newton(double x)//ţ�ٵ�����ʽ 
{
	double x0=x;
	while(fabs(f(x))>eps)
	{
		x-=f(x0)/fd(x0);
		x0=x;
	}
	return x;
}
int main()
{
	cin>>a>>b>>c>>d;
	double delta=4*b*b-12*a*c;
	double t1=(-2*b-sqrt(delta))/6/a,t2=(-2*b+sqrt(delta))/6/a;//������������ 
	double x1=Newton(t1-eps),x2=Newton((t1+t2)/2),x3=Newton(t2+eps);//ԭ���̵���������ţ�ٵ�����ʽ�õ� 
	printf("%.2f %.2f %.2f",x1,x2,x3);
	return 0;
}
