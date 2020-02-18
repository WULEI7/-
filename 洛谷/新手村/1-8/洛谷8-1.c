#include <stdio.h>
int main()
{
	float s,x,v=7,tot=0;
	scanf("%f %f",&s,&x);
	while(tot<s-x)
	{
		tot+=v;
		v*=0.98;
	}
	if(tot+v>s+x) printf("n");
	else printf("y");
	return 0;
}
