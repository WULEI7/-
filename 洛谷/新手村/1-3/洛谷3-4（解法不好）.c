#include <stdio.h>
int main()
{
	int x,n,a,b,s;
	scanf("%d %d",&x,&n);
	a=n/7;
	b=n%7;
	if(b==0)
	s=(a*5)*250;
	else
	{
	    if(b+x-1<=5)
	    s=(a*5+b)*250; 
	    if(b+x-1==6||x==7)
	    s=(a*5+b-1)*250;
	    else if(b+x-1>=7)
	    s=(a*5+b-2)*250;
	}
	printf("%d",s);
	return 0;
 } 
