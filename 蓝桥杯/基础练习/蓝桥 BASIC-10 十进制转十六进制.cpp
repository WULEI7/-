#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;
char num[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
int main()
{
	int n,t;
	stack<char> s;
	cin>>n;
	while(n!=0)
	{
		s.push(num[n%16]);
		n/=16;
	}
	if(s.empty())
		printf("0\n");//注意考虑数字为0的情况！ 
	while(!s.empty())
	{
		printf("%c",s.top());
		s.pop();
	}
	return 0;
}
