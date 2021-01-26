#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	char pic[26][26];
	int n,m;
	cin>>n>>m;
	pic[0][0]='A';
	for(int i=0;i<n;i++)
	{
		pic[i][0]='A'+i;
		for(int a=i,b=0;a<n&&b<m;a++,b++)
			pic[a][b]=pic[i][0];
	}
	for(int j=0;j<m;j++)
	{
		pic[0][j]='A'+j;
		for(int a=0,b=j;a<n&&b<m;a++,b++)
			pic[a][b]=pic[0][j];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
			printf("%c",pic[i][j]);
		printf("\n");
	}
	return 0;
}
