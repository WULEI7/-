#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;
int main()
{
	int a,b,c;
	cin>>a>>b;
	c=a+b;
	if(c==0)
	{
		cout<<0<<endl;
		return 0;
	}
	if(c<0)
	{
		c=-c;
		cout<<"-"<<endl;
	}
	stack<int> s;
	while(c)
	{
		s.push(c%10);
		c/=10;
	}
	while(s.size())
	{
		cout<<s.top()<<endl;
		s.pop();
	}
	return 0;
}
