#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int len;
	string a,b;
	cin>>len;
	cin>>a>>b;
	int flag=1;
	for(int i=0;i<len;i++)
		if(b[i]>a[i])
		{
			flag=0;
			break;
		}
	if(flag==0)
		cout<<"-1"<<endl;
	else
		cout<<b<<endl;
	return 0;
}
