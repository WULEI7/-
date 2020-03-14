#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s1,s2;
	int flag=0;
	getline(cin,s1);
	getline(cin,s2);
	for(int i=0;i<s1.length();i++)
		for(int j=0;j<s2.length();j++)
			if(s1[i]==s2[j])
			{flag=1;break;}
	if(flag) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}
