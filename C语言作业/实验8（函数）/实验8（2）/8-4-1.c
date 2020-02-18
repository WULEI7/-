#include <stdio.h>
void change(int a[],int k)
{
	int i,max,max0,min,min0,temp;
	max=a[0];min=a[0];
	max0=0;min0=0;
	for(i=1;i<k;i++)
	{
		if(a[i]>max)
			{max=a[i];max0=i;}
		if(a[i]<min)
			{min=a[i];min0=i;}
	}
	temp=a[max0];
	a[max0]=a[min0];
	a[min0]=temp;
}
void main()
{
	int b[10],i,k;
	for(i=0;i<10;i++)
		scanf("%d",&b[i]);
	k=sizeof(b)/sizeof(b[0]);
	printf("Before change the max and min's position:\n");
	for(i=0;i<10;i++)
		printf("%d ",b[i]);
	change(b,k);
	printf("\nAfter change the max and min's position:\n");
	for(i=0;i<10;i++)
		printf("%d ",b[i]);
}
