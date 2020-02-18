#include <stdio.h>
int main()
{  
	int a[12],i,n=12;
	float av=0;
   	for(i=0;i<n;i++) scanf("%d",&a[i]);
   	for(i=0;i<n;i++)
   	{ printf("%d ",a[i]);
     if (i%3==2) printf("\n");
   	}
   	for(i=0;i<n;i++) av+=a[i];
   	printf("av=%f\n",av/12);
   	return 0;
}
