#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
bool isVowel(char x)
{
	if(x=='a'||x=='e'||x=='i'||x=='o'||x=='u')
		return true;
	else return false;
}
int main()
{
	string s;
	int flag=1;
	cin>>s;
	for(int i=0;i<s.length()-1;i++)
	{
		if(!isVowel(s[i])&&s[i]!='n')
			if(!isVowel(s[i+1]))
			{flag=0;break;}
	}
	if(!isVowel(s[s.length()-1])&&s[s.length()-1]!='n')
		flag=0;
	if(flag) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}
