#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	vector <double> v;
	double t;
	ifstream is("a.txt");
	if(is)
	{
		while(is>>t)
			v.push_back(t);
	}
	else
	{
		cout<<"EPPOR: Cannot open file 'a.txt'."<<endl;
	}
	is.close();
	sort(v.begin(),v.end());
	//for(vector<int>::iterator i=v.begin();i!=v.end();i++)
	//	cout<<*i<<endl;
	//for(int i=0;i<v.size();i++)
	//	cout<<v[i]<<endl;
	ofstream os("b.txt");
	os<<v[0];
	for(unsigned int i=1;i<v.size();i++)
		os<<" "<<v[i];
	return 0;
}
