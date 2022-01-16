#include <iostream>
#include <cstdio>
#include <string>
#include <stack>
#include <sstream>
using namespace std;
int main()
{
	stringstream ss;
	string str;
	while(getline(cin,str))
	{
		if(str=="0") break;
		ss.clear();
		ss<<str;
		stack<double> s;
		double temp,ans=0;
		int n;
		char t;
		ss>>n;
		s.push(n);
		while(ss>>t)
		{
			ss>>n;
			if(t=='*')
			{
				temp=s.top();
				s.pop();
				s.push(temp*n);
			}
			else if(t=='/')
			{
				temp=s.top();
				s.pop();
				s.push(temp/n);
			}
			else if(t=='+')
				s.push(n);
			else if(t=='-')
				s.push(-n);
		}
		while(s.size()>0)
		{
			ans+=s.top();
			s.pop();
		}
		printf("%.2f\n",ans);
	}
	return 0;
}
