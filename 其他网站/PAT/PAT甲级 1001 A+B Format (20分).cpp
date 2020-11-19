#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int a,b,c;
	cin>>a>>b;
	c=a+b;
	if(c==0)
		printf("0\n");
	else
	{
		int flag;
		if(c>0)
			flag=0;
		else
		{
			flag=1;
			c=-c;
		}
		stack<int> s;
		while(c)
		{
			s.push(c%10);
			c/=10;
		}
		if(flag==1)
			printf("-");
		int size=s.size();
		while(size)
		{
			printf("%d",s.top());
			s.pop();
			size--;
			if(size%3==0&&size>0)
				printf(",");
		}
		printf("\n");
	}
	return 0;
}
