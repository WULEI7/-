#include <stdio.h>
int main()
{
	int x,y;
	scanf("%d",&x);
	if(x<5) y=1-x*x*x;
	else if(x>=5&&x<15) y=x-1;
	else if(x>=15) y=2*x*x-1;
	printf("%d",y);
	return 0;
}
