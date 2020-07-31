#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;
int main()
{
	int n;
	char x[100][100];
	scanf("%d",&n);
	while(n--)
	{
		memset(x,0,sizeof(x));
		string s;
		cin>>s;
		int len=s.length();
		int m=(int)sqrt(len-1)+1;
		for(int i=0;i<m;i++)
			for(int j=0;j<m;j++)
				x[i][j]=s[i*m+j];
		for(int j=0;j<m;j++)
			for(int i=m-1;i>=0;i--)
				if((x[i][j]>='a'&&x[i][j]<='z')||(x[i][j]>='A'&&x[i][j]<='Z'))
					printf("%c",x[i][j]);
		printf("\n");
	}
	return 0;
}
