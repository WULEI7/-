#include <stdio.h>
#include <string.h>
int main()
{
	char a[100],b[100],*p,*q=b;
	int i,j,k;
	gets(a);
	gets(b);
	j=strlen(a);
	k=strlen(b);
	p=a+j;
	for(i=0;i<k;i++)
		*(p++)=*(q+i);
	puts(a);
	return 0;
}
