#include <iostream>
using namespace std;
const int pi=3.14159;

class Shape
{
	public:
		Shape(int id)
		{
			m_ID=id;
			cout<<"Shape constructor called:"<<m_ID<<endl;
		}
		~Shape()
		{
			cout<<"Shape destructor called:"<<m_ID<<endl;
		}
		void setID(int id)
		{
			m_ID=id;
		}
		int getID()
		{
			return m_ID;
		}
		int getArea()
		{
			return 0;
		}
	private:
		int m_ID;
};
class Circle:public Shape
{
	public:
		Circle(int r,int id):Shape(id) 
		{
			R=r;
			cout<<"Circle constructor called:"<<getID()<<endl;
		}
		~Circle()
		{
			cout<<"Circle destructor called:"<<getID()<<endl;
		}
		void setR(int r)
		{
			R=r;
		}
		int getR()
		{
			return R;
		}
		int getArea()
		{
			return pi*R*R;
		}
	private:
		int R;
};
class Rectangle:public Shape
{
	public:
		Rectangle(int h,int w,int id):Shape(id)
		{
			H=h;
			W=w;
			cout<<"Rectangle constructor called:"<<getID()<<endl;
		}
		~Rectangle()
		{
			cout<<"Rectangle destructor called:"<<getID()<<endl;
		}
		void setH(int h)
		{
			H=h;
		}
		void setW(int w)
		{
			W=w;
		}
		int getH()
		{
			return H;
		}
		int getW()
		{
			return W;
		}
		int getArea()
		{
			return H*W;
		}
	private:
		int H,W;
};

int main()
{
	Shape s(1);//1表示ID 
	Circle c(4,2);//4表示半径，2表示ID 
	Rectangle r(4,5,3);//4和5表示长和宽，3表示ID 
	cout<<"Shape的面积"<<s.getArea()<<endl;
	cout<<"Circle的面积"<<c.getArea()<<endl;
	cout<<"Rectangle的面积"<<r.getArea()<<endl;
}
