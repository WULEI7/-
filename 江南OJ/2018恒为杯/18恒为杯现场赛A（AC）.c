#include <stdio.h>
int main()
{
	int n,i,s=0,t,c;
	scanf("%d",&n);
	c=n/3*2;
	n=n%3+1;
	if(n%3==0) c+=n/3*2;
	else c+=n/3*2+1;
	c--;
	printf("%d",c);
	return 0;
}
