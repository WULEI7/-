#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	double a,b,c,d,A,B,S,T,x1,x2,x3;
	cin>>a>>b>>c>>d;
	A=b*b-3*a*c;
	B=b*c-9*a*d;
	T=(2*A*b-3*a*B)/2/sqrt(A*A*A);
	S=acos(T);
	x1=(-b-2*sqrt(A)*cos(S/3))/3/a;
	x2=(-b+sqrt(A)*(cos(S/3)-sqrt(3)*sin(S/3)))/3/a;
	x3=(-b+sqrt(A)*(cos(S/3)+sqrt(3)*sin(S/3)))/3/a;
	printf("%.2f %.2f %.2f",x1,x2,x3);
	return 0;
}
