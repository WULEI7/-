#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int c;
	cin>>c;
	if(c<-10)
		cout<<c<<" Zhai"<<endl;
	else if(c<15)
		cout<<c<<" YuRongFu"<<endl;
	else
		cout<<c<<" Mama"<<endl; 
	return 0;
}
