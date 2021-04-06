#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
void postorder(string s)
{
	if(s.length()>1)
	{
		postorder(s.substr(0,s.length()/2));
		postorder(s.substr(s.length()/2,s.length()/2));
	}
	int flag0=0,flag1=0;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='0') flag0=1;
		if(s[i]=='1') flag1=1;
	}
	if(flag0==1&&flag1==0) cout<<"B";
	if(flag0==0&&flag1==1) cout<<"I";
	if(flag0==1&&flag1==1) cout<<"F";
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t,n;
	string s;
	cin>>t;
	while(t--)
	{
		cin>>n>>s;
		postorder(s);
		cout<<endl; 
	}
	return 0;
}
