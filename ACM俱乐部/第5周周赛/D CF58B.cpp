#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	cout<<n;
	while(n>1)
	{
		for(int i=n/2;i>=1;i--)
			if(n%i==0)
			{
				cout<<" "<<i;
				n=i;
				break;
			}
	}
	return 0;
}
