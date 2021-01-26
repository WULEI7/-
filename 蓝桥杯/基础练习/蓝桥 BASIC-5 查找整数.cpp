#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,a[1005],t,pos=-1;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	cin>>t;
	for(int i=1;i<=n;i++)
		if(a[i]==t)
		{
			pos=i;
			break;
		}
	cout<<pos<<endl;
	return 0;
}
