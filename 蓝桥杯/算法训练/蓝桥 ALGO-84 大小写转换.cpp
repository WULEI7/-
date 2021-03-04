#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int main()
{
	string s;
	cin>>s;
	int len=s.length();
	for(int i=0;i<len;i++)
	{
		if(s[i]>='A'&&s[i]<='Z') s[i]+=32;
		else if(s[i]>='a'&&s[i]<='z') s[i]-=32;
	}
	cout<<s<<endl;
	return 0;
}
