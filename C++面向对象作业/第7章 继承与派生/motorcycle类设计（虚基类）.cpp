#include <iostream>
using namespace std;

class vehicle
{
	public:
		vehicle(int m,int w)
		{
			maxspeed=m;
			weight=w;
			cout<<"vehicle constructor called. maxspeed:"<<maxspeed<<"; weight"<<weight<<endl;
		}
		~vehicle()
		{
			cout<<"vehicle destructor called. maxspeed:"<<maxspeed<<"; weight"<<weight<<endl;
		}
		void run()
		{
			cout<<"vehicle run"<<endl;
		}
		void stop()
		{
			cout<<"vehicle stop"<<endl;
		}
	private:
		int maxspeed,weight;
};
class bicycle:virtual public vehicle
{
	public:
		bicycle(int h,int m,int w):vehicle(m,w)
		{
			height=h;
			cout<<"bicycle constructor called. height:"<<height<<endl;
		}
		~bicycle()
		{
			cout<<"bicycle destructor called. height:"<<height<<endl;
		}
	private:
		int height;
};
class motorcar:virtual public vehicle
{
	public:
		motorcar(int s,int m,int w):vehicle(m,w)
		{
			seatnum=s;
			cout<<"motorcar constructor called. setnum:"<<seatnum<<endl;
		}
		~motorcar()
		{
			cout<<"motorcar destructor called. setnum:"<<seatnum<<endl;
		}
	private:
		int seatnum;
};
class motorcycle:virtual public bicycle,virtual public motorcar
{
	public:
		motorcycle(int h,int s,int m,int w):vehicle(m,w),bicycle(h,m,w),motorcar(s,m,w)
		{
			cout<<"motorcycle constructor called"<<endl;
		}
		~motorcycle()
		{
			cout<<"motorcycle destructor called"<<endl;
		}
};

int main(int argc,char *argv[])
{
	motorcycle m(1,2,3,4);//1表示height，2表示setnum，3表示maxspeed，4表示weight 
	m.run();
	m.stop();
	return 0;
}
