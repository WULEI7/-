#include <stdio.h>
int main()
{
	int a,b,n,i,s=0;
	scanf("%d %d",&a,&n);
	printf("%d",a);
	s=a;b=a;
	for(i=1;i<n;i++){
		b=b*10+a;
		s+=b;
		printf("+%d",b);
	}
	printf("=%d",s);
	return 0;
}
