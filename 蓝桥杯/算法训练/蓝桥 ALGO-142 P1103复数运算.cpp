#include <iostream>
#include <cstdio> 
using namespace std;
class Complex
{
	public:
	Complex(double r=0.0,double i=0.0):real(r),imag(i){}
	Complex operator + (Complex &c)
	{
		return Complex(real+c.real,imag+c.imag);
	}
	Complex operator - (Complex &c)
	{
		return Complex(real-c.real,imag-c.imag);
	}
	Complex operator * (Complex &c)
	{
		return Complex(real*c.real-imag*c.imag,real*c.imag+imag*c.real);
	}
	Complex operator / (Complex &c)
	{
		Complex t(real*c.real+imag*c.imag,imag*c.real-real*c.imag);
		t.real/=(c.real*c.real+c.imag*c.imag);
		t.imag/=(c.real*c.real+c.imag*c.imag);
		return t;
	}
	void print()
	{
		printf("%.2f+%.2fi",real,imag);
	}
	private:
		double real,imag;
};

int main()
{
	char ch;
	double x,y,m,n;
	cin>>ch>>x>>y>>m>>n;
	Complex a(x,y),b(m,n),c;
	if(ch=='+')
		c=a+b;
	if(ch=='-')
		c=a-b;
	if(ch=='*')
		c=a*b;
	if(ch=='/')
		c=a/b;
	c.print();
	return 0;
}
