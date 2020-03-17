#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
const double PI=3.1415926;

class cylinder{
public:
	cylinder(double inith,double initr);
	~cylinder(); 
	double getvolumn(); 
	double getarea();
private:
	double h,r;
};
cylinder::cylinder(double inith,double initr)
{
	h=inith;
	r=initr;
	cout<<"构造函数被调用"<<endl; 
}
cylinder::~cylinder()
{
	cout<<"析构函数被调用"<<endl; 
}
double cylinder::getvolumn()
{
	return PI*r*r*h;
}
double cylinder::getarea()
{
	return 2*PI*r*(r+h);
}

int main()
{
	double d,h;
	cin>>d>>h;
	cylinder can(h,d/2);
	cout<<fixed<<setprecision(6);
	cout<<"油桶的容积是"<<can.getvolumn()<<" "<<endl;
	cout<<"铁皮的面积是"<<can.getarea()<<endl;
}
