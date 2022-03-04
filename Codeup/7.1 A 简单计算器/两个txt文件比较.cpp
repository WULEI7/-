#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
using namespace std;
int main()
{
	ifstream fin0("test0.out");
	ifstream fin1("test1.out");
	string a,b;
	for(int i=1;i<=1000;i++) 
	{
		getline(fin0,a);
		getline(fin1,b);
		if(a!=b) cout<<"²»Í¬£º"<<i<<endl;
	}
	return 0;
}
