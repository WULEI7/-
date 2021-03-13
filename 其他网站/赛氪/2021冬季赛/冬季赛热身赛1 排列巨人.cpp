#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	long long n=1;
	for(int i=1;i<=12;i++)
		n*=i;
	cout<<n<<endl;
	return 0;
}
