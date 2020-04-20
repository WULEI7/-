#include <iostream>
using namespace std;

class Point
{
	public:
		Point(int xx=0,int yy=0):x(xx),y(yy){}
		Point & operator ++ ()
		{
			x++;
			y++;
			return *this;
		}
		Point operator ++ (int)
		{
			Point old=*this;
			++(*this);
			return old;
		}
		friend ostream & operator << (ostream &out,const Point &p)
		{
			cout<<"("<<p.x<<","<<p.y<<")"<<endl;
			return out;
		}
	private:
		int x,y;	
};

int main()
{
	Point a(1,3);
	cout<<a;
	cout<<a++;
	cout<<++a;
	return 0;
}
