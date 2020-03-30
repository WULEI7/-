#include <iostream>
#include <iomanip>
using namespace std;
void cnminus(float a,float b,float c,float d)
{
	cout<<fixed<<setprecision(2)<<a-c<<" ";
	cout<<fixed<<setprecision(2)<<b-d<<endl;
}
int main()
{
	float a,b,c,d;
	cin>>a>>b>>c>>d;
	cnminus(a,b,c,d);
	return 0;
}
