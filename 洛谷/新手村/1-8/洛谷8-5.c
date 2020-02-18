#include <stdio.h>
int main()
{
	int a,b,flag=0;
	scanf("%d",&a);
	if(a==0) printf("0");
	else
	{
		if(a<0) {a=0-a;printf("-");}
		while(a!=0)
		{
			b=a%10;
			if(b!=0) flag=1;
			if(flag) printf("%d",b);
			a/=10;
		}
	}
	return 0;
}
