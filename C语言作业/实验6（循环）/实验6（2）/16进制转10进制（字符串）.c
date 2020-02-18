#include <stdio.h>
#include "string.h"
int main()
{
	char b[100];
	int i,k,d=1,c=0;
	gets(b);
	k=strlen(b);
	for(i=k-1;i>=0;i--)
	{	
		if(b[i]>='A'&&b[i]<='F') b[i]-=55;
		else if(b[i]>='0'&&b[i]<='9') b[i]-=48;
		c+=b[i]*d;
		d*=16;
	}
	printf("%d",c);
	return 0;
}
