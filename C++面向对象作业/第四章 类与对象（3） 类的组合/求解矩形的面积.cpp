#include <iostream>
#include <cmath>
using namespace std;

class CPoint
{
	public:
		CPoint(int xx=0,int yy=0)
		{
			x=xx;
			y=yy;
			cout<<"CPoint contstructor with default value(0,0) is called."<<endl;
		}
		CPoint(CPoint &p)
		{
			x=p.x;
			y=p.y;
			cout<<"CPoint copy contstructor is called."<<endl;
		}
		int getX() {return x;}
		int getY() {return y;}
	private:
		int x,y;
};

class CRectangle
{
	public:
		CRectangle();
		CRectangle(CPoint xp1,CPoint xp2);
		CRectangle(int a,int b,int c,int d);
		CRectangle(CRectangle &r);
		int GetArea()
		{
			return abs((p1.getX()-p2.getX())*(p1.getY()-p2.getY()));
		}
	private:
		CPoint p1,p2;
};

CRectangle::CRectangle():p1(),p2()
{
	cout<<"CRectangle default contstructor is called."<<endl;
}
CRectangle::CRectangle(CPoint xp1,CPoint xp2):p1(xp1),p2(xp2)
{
	cout<<"CRectangle contstructor with (CPoint,CPoint) is called."<<endl;
}
CRectangle::CRectangle(int a,int b,int c,int d):p1(a,b),p2(c,d)
{
	cout<<"CRectangle contstructor with (int,int,int,int) is called."<<endl;
}
CRectangle::CRectangle(CRectangle &r):p1(r.p1),p2(r.p2)
{
	cout<<"CRectangle copy contstructor is called."<<endl;
}

int main()
{
	int a=1,b=1,c=6,d=11;
	cout<<"# Define p1 ######"<<endl;
	CPoint p1;
	cout<<"# Define p2 ######"<<endl;
	CPoint p2(10,20);
	cout<<"# Define rect1 ######"<<endl;
	CRectangle rect1;
	cout<<"# Define rect2 ######"<<endl;
	CRectangle rect2(p1,p2);
	cout<<"# Define rect3 ######"<<endl;
	CRectangle rect3(a,b,c,d);
	cout<<"# Define rect4 ######"<<endl;
	CRectangle rect4(rect2);
	cout<<"# Calculate area ######"<<endl;
	cout<<"rect1面积为"<<rect1.GetArea()<<endl;
	cout<<"rect2面积为"<<rect2.GetArea()<<endl;
	cout<<"rect3面积为"<<rect3.GetArea()<<endl;
	cout<<"rect4面积为"<<rect4.GetArea()<<endl;
	system("pause");
	return 0;
}
