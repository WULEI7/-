#include <stdio.h>
int main()
{
	int a;
	float b;
	scanf("%d",&a);
	if(a<=150)
	{
		b=a*0.4463;
	}
	if(a>150&&a<=400)
	{
		b=150*0.4463+(a-150)*0.4663;
	}
	if(a>=401)
	{
		b=150*0.4463+250*0.4663+(a-400)*0.5663;
	}
	printf("%.1f\n",b);
	return 0;
 } 
