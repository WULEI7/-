#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,a;
	cin>>n;
	for(int i=n;i>=0;i--)
	{
		cin>>a;
		if(a==0)
			continue;
		if(a>0&&i<n)
			cout<<"+";
		if(a<-1||a>1||i==0)
			cout<<a;
		if(a==-1&&i>0)
			cout<<"-";
		if(i>=2)
			cout<<"x^"<<i;
		if(i==1)
			cout<<"x";
	}
	return 0;
}
