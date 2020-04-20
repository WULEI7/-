#include <iostream>
using namespace std;
class Complex
{
	public:
	Complex(double r=0.0,double i=0.0):real(r),imag(i){}
	Complex operator + (Complex &c)
	{
		return Complex(real+c.real,imag+c.imag);
	}
	Complex operator + (double c)
	{
		return Complex(real+c,imag);
	}
	Complex operator - (Complex &c)
	{
		return Complex(real-c.real,imag-c.imag);
	}
	Complex operator - (double c)
	{
		return Complex(real-c,imag);
	}
	void print()
	{
		cout<<real<<"+"<<imag<<"i";
	}
	private:
		double real,imag;	
};

int main()
{
	Complex a(3,4),b(1,-1),c;
	c=a+b;
	cout<<"a+b=";
	c.print();
	cout<<endl;
	c=a-b;
	cout<<"a-b=";
	c.print();
	cout<<endl;
	c=a+100;
	cout<<"a+100=";
	c.print();
	cout<<endl;
	c=a-2.5;
	cout<<"a-2.5=";
	c.print();
	cout<<endl;
	return 0;
}
