#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int N;
	scanf("%d",&N);
	while(N--)
	{
		int n,temp,ans=0;
		char t;
		scanf("%d",&temp);
		while(scanf("%c",&t))
		{
			if(t=='\n') break;
			scanf("%d",&n);
			if(t=='x')
				temp=temp*n;
			else if(t=='/')
				temp=temp/n;
			else if(t=='+')
			{
				ans+=temp;
				temp=n;
			}
			else if(t=='-')
			{
				ans+=temp;
				temp=-n;
			}
		}
		ans+=temp;
		if(ans==24)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
