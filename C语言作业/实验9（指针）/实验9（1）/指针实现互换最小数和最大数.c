#include <stdio.h>

void input(int *number,int n)
{
	int i;
	for(i=0;i<n;i++)
		scanf("%d",number+i);
}

void max_min_value(int *number,int n)
{
	int i,t,*max,*min;
	min=number;max=number+n-1;
	for(i=1;i<n;i++)
		if(*(number+i)<*min) min=number+i;
	t=*number;*number=*min;*min=t;
	for(i=0;i<n-1;i++)
		if(*(number+i)>*max) max=number+i;
	t=*(number+n-1);*(number+n-1)=*max;*max=t;
}

void output(int *number,int n)
{
	int i;
	for(i=0;i<n;i++)
		printf("%d ",*(number+i));
}

void main()
{
	int a[10];
	printf("input 10 numbers:");
	input(a,10);
	max_min_value(a,10);
	printf("Now,they are:    ");
	output(a,10);
}
