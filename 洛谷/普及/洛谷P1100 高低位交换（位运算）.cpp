#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	unsigned long long n,m;
	cin>>n;
	m=(n&0x0000ffff)<<16|(n&0xffff0000)>>16;
	cout<<m<<endl;
	return 0;
}
