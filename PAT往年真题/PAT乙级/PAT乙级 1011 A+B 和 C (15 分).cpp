#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;
	long long a,b,c;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>b>>c;
		if(a+b>c)
			cout<<"Case #"<<i<<": true"<<endl;
		else
			cout<<"Case #"<<i<<": false"<<endl;
	}
	return 0; 
}
