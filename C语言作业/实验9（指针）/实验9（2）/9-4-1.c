#include <stdio.h>
#include <string.h>
int main()
{
	char a[100],*p=a;
	int b=0,i,k;
	gets(a);
	k=strlen(a);
	for(i=0;i<k;i++)
		if(*(p+i)>='0'&&*(p+i)<='9')
			b=b*10+*(p+i)-'0';
	printf("%d",b);
}
