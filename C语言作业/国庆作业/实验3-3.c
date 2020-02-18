#include <stdio.h>
#include <math.h>
int main()
{
	int X,Y,W;
	printf("input year:\n");
	scanf("%d",&Y);
	X=Y-1+floor((Y-1)/4)-floor((Y-1)/100)+floor((Y-1)/400)+1;
	W=X-floor(X/7)*7;
	printf("%d年的元旦是星期%d",Y,W);
	return 0;
 } 
