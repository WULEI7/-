#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	for(int i=1;i<=9;i++)
	for(int j=0;j<=9;j++)
		printf("%d%d%d%d\n",i,j,j,i);
	return 0;
}
