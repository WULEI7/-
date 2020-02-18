#include <stdio.h>
int main()
{
	int a,c,d=0,e=1,i=0;
	scanf("%d",&a);
	while(a!=0){
		c=a%2;a=a/2;
		d=d+c*e;
		e*=10;
	}
	printf("%d",d);
	return 0;
}
