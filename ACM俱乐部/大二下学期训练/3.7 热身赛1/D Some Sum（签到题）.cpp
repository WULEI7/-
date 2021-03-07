#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int n;
	cin>>n;
	if(n%2==1)
		cout<<"Either"<<endl;
	else
	{
		if((n/2)%2==1)
			cout<<"Odd"<<endl;
		if((n/2)%2==0)
			cout<<"Even"<<endl;
	}
	return 0;
}
