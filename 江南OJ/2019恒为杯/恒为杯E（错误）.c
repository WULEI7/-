#include <stdio.h>
#include <math.h>
int main()
{
	long long a,b,c,i;
	double s;
	while(scanf("%lld",&a)!=EOF)
	{
		for(i=a;i<4000000;i++)
		{
			s=sqrt(a*a+i*i);
			if((int)s==s)
			{b=i;c=s;break;}
		}
		printf("%d %d\n",b,c);
	}	
	return 0;
}
