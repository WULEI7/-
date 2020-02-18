#include <stdio.h>
#define n 10
int main()
{
	int a[n+1],b,i,j,t;
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++)
			if(a[i]<a[j])
			{t=a[i];a[i]=a[j];a[j]=t;}
	printf("After sort,array a is :");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\nPlease input a number to insert into array a:\n");
	scanf("%d",&b);
	a[10]=0; 
	for(i=0;i<n+1;i++)
		if(b>a[i]) break;
	for(j=n+1;j>i;j--)
	a[j]=a[j-1];
	a[i]=b;
	printf("After insert a new number,the sorted array a is :");
	for(i=0;i<n+1;i++)
		printf("%d ",a[i]);
	return 0;
}
