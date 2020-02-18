#include <stdio.h>
int main()
{
	int a=8,b=80,s=0;
	for(a=8;a<100;a+=10)
	s=s+a;
	for(b=80;b<=89;b++)
	s=s+b;
	s=s-88;
	printf("%d",s);
	return 0;
}
