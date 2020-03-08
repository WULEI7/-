#include <cstdio>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
char a[1000001];
int main()
{
	string a;
	int temp=0,ans=0;
	cin>>a;
	for(int i=0;i<a.length();i++)
	{
		if(a[i]=='(') temp++;
		if(temp>0&&a[i]==')')
		{ans+=2;temp--;}
	}
	cout<<ans;
	return 0;
}
