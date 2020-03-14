#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
const double PI=3.1415926;

class cylinder{
public:
	void init(double initH,double initR)
	{
		h=initH;
		r=initR;
	}
	double getvolumn()
	{
		return PI*r*r*h;
	}
	double getarea()
	{
		return 2*PI*r*(r+h);
	}
private:
	double h,r;
};

int main()
{
	double d,h;
	cin>>d>>h;
	
	cylinder can;
	
	can.init(h,d/2);
	cout<<fixed<<setprecision(6);
	cout<<"油桶的容积是"<<can.getvolumn()<<" "<<endl;
	cout<<"铁皮的面积是"<<can.getarea()<<endl;
}
