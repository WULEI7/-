#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	string s[27];
	s[1]="A";
	for(int i=2;i<=26;i++)
	{
		char t='A'+i-1;
		s[i]=s[i-1]+t+s[i-1];
	}
	int n;
	cin>>n;
	cout<<s[n]<<endl;
	return 0;
}
