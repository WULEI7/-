#include <iostream>
#include <cstdio>
#include <string>
#include <cctype> 
using namespace std;
int main()
{
	int ans;
	string s,t;
	cin>>s>>t;
	int len1=s.length(),len2=t.length();
	if(len1!=len2)
		ans=1;
	else if(s==t)
		ans=2;
	else
	{
		for(int i=0;i<len1;i++)
			s[i]=tolower(s[i]);
		for(int i=0;i<len2;i++)
			t[i]=tolower(t[i]);
		if(s==t)
			ans=3;
		else
			ans=4;
	}
	cout<<ans<<endl;
	return 0;
}
