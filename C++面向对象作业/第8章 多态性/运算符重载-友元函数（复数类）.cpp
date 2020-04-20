#include <iostream>
using namespace std;

class Complex
{
	public:
		Complex(double r=0.0,double i=0.0):real(r),imag(i){}
		friend Complex operator + (Complex &c1,Complex &c2)
		{
			return Complex(c1.real+c2.real,c1.imag+c2.imag);
		}
		friend Complex operator - (Complex &c1,Complex &c2)
		{
			return Complex(c1.real-c2.real,c1.imag-c2.imag);
		}
		friend Complex operator + (Complex &c1,double c2)
		{
			return Complex(c1.real+c2,c1.imag);
		}
		friend Complex operator - (Complex &c1,double c2)
		{
			return Complex(c1.real-c2,c1.imag);
		}
		friend Complex operator + (double c1,Complex &c2)
		{
			return Complex(c1+c2.real,c2.imag);
		}
		friend Complex operator - (double c1,Complex &c2)
		{
			return Complex(c1-c2.real,-c2.imag);
		}
		void print()
		{
			cout<<"("<<real<<")+("<<imag<<"i)";
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
	c=100+a;
	cout<<"100+a=";
	c.print();
	cout<<endl;
	c=2.5-a;
	cout<<"2.5-a=";
	c.print();
	cout<<endl;
	return 0;
}
