#include <stdio.h>
int main()
{
	int i=1,n;
	scanf("%d",&n);
	while(n>i)
	{
		n-=i;
		i++;
	}
	if(i%2==1) printf("%d/%d",i+1-n,n);
	else printf("%d/%d",n,i+1-n);
	return 0;
}
