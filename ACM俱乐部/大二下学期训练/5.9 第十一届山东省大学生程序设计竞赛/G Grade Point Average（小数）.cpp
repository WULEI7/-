#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,k,a,t=0;
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		t+=a;
	}
	cout<<t/n<<".";
	for(int i=0;i<k;i++)
	{
		t=(t-t/n*n)*10;
		cout<<t/n;
	}
	return 0;
}
