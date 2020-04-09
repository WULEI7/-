#include <iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int a[4]={1,9,41,109};
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		unsigned long long n;
		cin>>n;
		if(n<=3)
			cout<<"Case #"<<i<<": "<<a[n]<<endl;
		else
			cout<<"Case #"<<i<<": "<<14*n*n-6*n+5<<endl;
	}
	return 0;
}
