#include<stdio.h>
int main()
{
	int i, max=0, x, y, f=0;
	for (i=1; i<=7; i++)
	{
		scanf("%d %d", &x, &y);
		if (x+y > max)
		{
			max = x+y;
			f = i;
		}
	}	
	printf("%d", f);
} 
