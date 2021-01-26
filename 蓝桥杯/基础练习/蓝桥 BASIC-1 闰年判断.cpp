#include <iostream>
#include <cstdio>
using namespace std;
int isleap(int n)
{
	if(n%100!=0&&n%4==0||n%400==0)
		return 1;
	return 0;
}
int main()
{
	int n;
	cin>>n;
	if(isleap(n)==1)
		cout<<"yes"<<endl;
	else
		cout<<"no"<<endl;
	return 0;
}
