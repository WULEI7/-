#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
string a,b;
void build(int l1,int r1,int l2,int r2)
{
	for(int i=l1;i<=r1;i++)
	{
		if(b[i]==a[r2])
		{
			cout<<a[r2];
			build(l1,i-1,l2,l2-l1+i-1);
			build(i+1,r1,l2-l1+i,r2-1);
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
