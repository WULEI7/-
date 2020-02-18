#include <stdio.h>
int main()
{
	int a,b,c,n,s=0;
	scanf("%d",&n);
	for(a=0;a<=n;a++){
		for(b=0;b<=n/2;b++){
			for(c=0;c<=n/3;c++){
				if(a+2*b+3*c==n) s++;
			}
		}
	}
	printf("%d",s);
	return 0;
}
