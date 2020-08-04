#include <cstdio>
#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main()
{
	int n;
	cin>>n;
	getchar();
	while(n--)
	{
		int flag=1;
		stack<char> s;
		string str;
		getline(cin,str);
		for(int i=0;i<str.length();i++)
		{
			if(str[i]=='('||str[i]=='[')
				s.push(str[i]);
			if(str[i]==')'||str[i]==']')
			{
				if(s.empty())
				{flag=0;break;}
				else if(s.top()=='('&&str[i]==']')
				{flag=0;break;}
				else if(s.top()=='['&&str[i]==')')
				{flag=0;break;}
				else s.pop();
			}
		}
	    if(s.empty()&&flag)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
}
