#include <stdio.h>
#include <math.h>
int main()
{
	int n,a,b,c=0;
	scanf("%d",&n);
	for(a=pow(10,n-1);a<pow(10,n);a++)
	{
		b=a;
		while(b!=0){
			c+=pow(b%10,n);
			b/=10;
		}
		if(a==c) printf("%d\n",a);
		c=0;
	}
	return 0;
}
