#include <stdio.h>
int main()
{
	int i,k=1,b=0,c; 
	char a[15];
	gets(a);
	for(i=0;i<=11;i++)
	{
		if(a[i]>='0'&&a[i]<='9')
		{
			b+=(a[i]-48)*k;
			k++;
		}
	}
	c=b%11;
	if(c==10)
	{
		if(a[12]=='X') printf("Right\n");
		else {a[12]='X';puts(a);}
	}
	if(c!=10)
	{ 
	if(c==(a[12]-48)) printf("Right\n");
	else if(c!=(a[12]-48))
	{a[12]=c+48;puts(a);}
	}
	return 0;
}
