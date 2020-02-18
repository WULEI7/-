#include <stdio.h>
int move(int n,char x,char y,char z)
{
	static int sum0=0;
	if(n==1) printf("%c->%c ",x,z);
	else
	{
		move(n-1,x,z,y);
		printf("%c->%c ",x,z);
		move(n-1,y,x,z);
	}
	sum0++;
	return sum0;
}
void main()
{
	int h,sum;
	printf("input number:");
	scanf("%d",&h);
	printf("The steps to move %d diskes:\n",h);
	sum=move(h,'A','B','C');
	printf("\nTotally %d steps\n",sum);
}
