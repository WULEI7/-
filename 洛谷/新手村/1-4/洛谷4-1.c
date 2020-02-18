#include <stdio.h>
int a[10],b,c,i=0,m=0,n=0;
int main()
{
	for (i=0;i<10;i++)
	scanf("%d",&a[i]);
	scanf("%d",&b);
	for (m=0;m<10;m++)
	{
		c=b+30;
		if(a[m]<=c)
		n++;
	}
	printf("%d\n",n);
	return 0;
 } 
