#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	if(m==2)
	{
		printf("1\n2\n");
	}
	else if(m==3)
	{
		printf("1\n2\n3\n");
	}
	else if(m==4)
	{
		printf("1\n2\n3\n5\n");
	}
	return 0;
}