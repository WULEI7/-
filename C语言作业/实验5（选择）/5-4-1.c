#include <stdio.h>
int main()
{
	int a,b,c,d,f,g,h;
	float e;
	scanf("%d%d%d",&a,&b,&c);
	d=a+b+c;
	e=(float)d/3;
	f=a*b*c;
	if(a<b) {
		g=a;h=b;
		if(c<a) g=c;
		else if(c>b) h=c;}
	else {
		g=b;h=a;
		if(c<b) g=c;
		else if(c>a) h=c;
	}
	printf("Sum=%d,Average=%.2f,product=%d,Min=%d,Max=%d\n",d,e,f,g,h);
	return 0;
}
