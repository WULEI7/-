#include <iostream>
#include <cstdio>
#include <stack>
#include <sstream>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;
	char c;
	bool a[26];
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>c;
		if(c=='T')
			a[i]=true;
		else
			a[i]=false;
	}
	cin.ignore(); 
	stringstream ss;
	string s;
	getline(cin,s);
	ss<<s;
	stack<bool> sta;
	while(ss>>c)
	{
		if(c>='A'&&c<='Z')
			sta.push(a[c-'A']);
		if(c=='*')
		{
			bool a=sta.top();
			sta.pop();
			bool b=sta.top();
			sta.pop();
			bool t=a&&b;
			sta.push(t);
		}
		if(c=='+')
		{
			bool a=sta.top();
			sta.pop();
			bool b=sta.top();
			sta.pop();
			bool t=a||b;
			sta.push(t);
		}
		if(c=='-')
		{
			bool a=sta.top();
			sta.pop();
			bool t=!a;
			sta.push(t);
		}
	}
	char t=sta.top();
	if(t==true)
		printf("T");
	else
		printf("F");
	return 0;
}
