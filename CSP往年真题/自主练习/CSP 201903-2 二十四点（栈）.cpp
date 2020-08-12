#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;
stack<int> s;
int main()
{
	int N;
	scanf("%d",&N);
	while(N--)
	{
		int temp,n;
		char t;
		scanf("%d",&n);
		s.push(n);
		while(scanf("%c",&t))
		{
			if(t=='\n') break;
			scanf("%d",&n);
			if(t=='x')
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
		temp=0;
		while(s.size()>0)
		{
			temp+=s.top();
			s.pop();
		}
		if(temp==24)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
