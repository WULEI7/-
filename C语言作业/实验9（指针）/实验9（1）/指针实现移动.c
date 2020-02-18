#include <stdio.h>
void move(int *a,int n,int m)
{
	int i,j,temp;
	for(i=0;i<m;i++)
	{
		temp=*(a+n-1);
		for(j=n-1;j>=1;j--)
			*(a+j)=*(a+j-1);
		*a=temp;
	}
}

void main()
{
	int n,m,i,a[100];
	printf("how many numbers?");
	scanf("%d",&n);
	printf("input %d numbers:\n",n);
	for(i=0;i<n;i++)
		scanf("%d",a+i);
	printf("how many place you want move?");
		scanf("%d",&m);
	move(a,n,m);	
	printf("Now,they are:\n");
	for(i=0;i<n;i++)
		printf("%d ",*(a+i));
}
