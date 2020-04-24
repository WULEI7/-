#include <iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n,b,ans;
		cin>>n>>b;
		for(long long i=0;i<9973;i++)
			if(b*i%9973==n)
			{
				cout<<i<<endl;
				break;
			}
	}
	return 0;
}
