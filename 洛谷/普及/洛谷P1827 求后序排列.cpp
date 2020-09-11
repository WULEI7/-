#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
string a,b;
void build(int l1,int r1,int l2,int r2)
{
	for(int i=l2;i<=r2;i++)
	{
		if(b[i]==a[l1])
		{
			build(l1+1,l1+i-l2,l2,i-1);
			build(l1+i-l2+1,r1,i+1,r2);
			cout<<a[l1];
			return;
		}
	}
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>b>>a;
	int len=a.length()-1;
	build(0,len,0,len);
	return 0;
}
