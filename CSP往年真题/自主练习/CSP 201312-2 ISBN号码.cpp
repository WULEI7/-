#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
	char c[13];
	scanf("%s",c);
	int a=(1*(c[0]-'0')+2*(c[2]-'0')+3*(c[3]-'0')+4*(c[4]-'0')+5*(c[6]-'0')+6*(c[7]-'0')+7*(c[8]-'0')+8*(c[9]-'0')+9*(c[10]-'0'))%11;
	char t;
	if(a<10)
		t=a+'0';
	else
		t='X';
	if(t==c[12])
		printf("Right\n");
	else
	{
		c[12]=t;
		printf("%s\n",c);
	}
	return 0;
}
