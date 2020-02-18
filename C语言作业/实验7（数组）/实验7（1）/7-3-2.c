#include <stdio.h>
#define SIZE 10
int main()
{   int i=0,base,n,j,num[20];
    scanf("%d",&n);
    scanf("%d",&base);
    do{	i++;
       	num[i]=n%base;
       	n=n/base;
    }
	while(n!=0);
    for(j=i;j>=1;j--)
    printf("%d",num[j]);
    return 0;
}

