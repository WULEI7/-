#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
using namespace std;
int main()
{
	string s; 
	cin>>s;
	int len=s.length();
	long long ans=0;
	for(int i=0;i<len;i++)
	{
		long long t;
		if(s[len-1-i]>='0'&&s[len-1-i]<='9')
			t=s[len-1-i]-'0';
		else
			t=s[len-1-i]-'A'+10;
		ans+=t*pow(16,i);
	}
	cout<<ans<<endl;
	return 0;
}
