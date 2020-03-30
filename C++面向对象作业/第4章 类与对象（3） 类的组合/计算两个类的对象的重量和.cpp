#include <iostream>
using namespace std;

class Car;
class Boat
{
	public:
		Boat(int w=0)
		{weight=w;}
		friend int totalweight(Boat& ,Car& );
	private:
		int weight;
};
class Car
{
	public:
		Car(int w=0)
		{weight=w;}
		friend int totalweight(Boat& ,Car& );
	private:
		int weight;
};

int totalweight(Boat& b,Car& c)
{
	return b.weight+c.weight;
}

int main()
{
	Boat b(100);
	Car c(200);
	cout<<totalweight(b,c)<<endl;
	return 0;
}
