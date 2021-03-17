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
	if(s==string(s.length(),'0')) printf("B");
	else if(s==string(s.length(),'1')) printf("I");
	else printf("F");
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	string s;
	cin>>s;
	postorder(s);
	return 0;
}
