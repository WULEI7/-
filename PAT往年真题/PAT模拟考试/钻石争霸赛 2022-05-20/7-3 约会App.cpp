#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int g,a,b,c,d,n,x,y,z;
	scanf("%d %d %d %d %d",&g,&a,&b,&c,&d);
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d %d %d",&x,&y,&z);
		if(x!=g&&y>=a&&y<=b&&z>=c&&z<=d)
			printf("%d %d %d\n",x,y,z);
	}
	return 0;
}
