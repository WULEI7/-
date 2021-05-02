#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,t;
	cin>>n;
	cin>>t;
	cout<<t;
	for(int i=1;i<n;i++)
	{
		cin>>t;
		cout<<" "<<t;
	}
	cout<<endl;
	return 0;
}
