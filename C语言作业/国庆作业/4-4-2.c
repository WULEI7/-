#include<stdio.h>
#include<math.h>
int main()
{
	float a,b,c,d;
	scanf("%f,%f,%f",&a,&b,&c);
	d = b*b - 4*a*c;
	if (a==0)
	{
		printf("The equation is not a quadratic");
		return 0;
	}
	if (d==0)
		printf("The equation has two equal roots:  %.4f",-b/2/a);
	if (d>0)
		printf("The equation has distinct real roots: %.4f and  %.4f", (-b+sqrt(d))/2/a, (-b-sqrt(d))/2/a);
	if (d<0)
		printf("The equation  has complex roots:\n %.4f+  %.4fi\n %.4f-  %.4fi", -b/2/a, sqrt(-d)/2/a, -b/2/a, sqrt(-d)/2/a);
	return 0;
}
