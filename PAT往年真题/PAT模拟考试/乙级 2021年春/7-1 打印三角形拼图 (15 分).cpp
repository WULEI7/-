#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int n;
	char a,b,c;
	cin>>n>>a>>b>>c;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i==j)
				printf("%c",c);
			if(i<j)
				printf("%c",a);
			if(i>j)
				printf("%c",b);
		}
		printf("\n");
	}
	return 0;
}
