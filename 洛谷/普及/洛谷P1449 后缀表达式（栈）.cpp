#include <iostream>
#include <cstdio>
#include <stack>
#include <string>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	string s;
	stack<int> num;
	stack<char> opt;
	cin>>s;
	int len=s.length()-1;
	for(int i=0;i<len;i++)
	{
		if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/')
		{
			int n2=num.top();
			num.pop();
			int n1=num.top();
			num.pop();
			if(s[i]=='+')
				num.push(n1+n2);
			if(s[i]=='-')
				num.push(n1-n2);
			if(s[i]=='*')
				num.push(n1*n2);
			if(s[i]=='/')
				num.push(n1/n2);
		}
		else
		{
			int temp=s[i]-'0';
			while(s[++i]!='.'&&i<len)
			{
				temp=temp*10+s[i]-'0';
			}
			num.push(temp);
		}
	}
	cout<<num.top()<<endl;
	return 0;
}
