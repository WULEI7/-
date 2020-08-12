#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;
stack<int> s;
int main()
{
	int temp,n;
	char t;
	scanf("%d",&n);
	n%=10000;
	s.push(n);
	while(scanf("%c",&t))
	{
		if(t=='\n') break;
		scanf("%d",&n);
		if(t=='*')
		{
			temp=s.top();
			s.pop();
			s.push(temp*n%10000);
		}
		else if(t=='+')
			s.push(n);
	}
	temp=0;
	while(s.size()>0)
	{
		temp+=s.top();
		s.pop();
		temp%=10000;
	}
	printf("%d\n",temp);
	return 0;
}
