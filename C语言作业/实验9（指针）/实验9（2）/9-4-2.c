#include <stdio.h>
#include <string.h>
int main()
{
	char a[100],*p=a;
	int i,k;
	gets(a);
	k=strlen(a);
	for(i=0;i<k;i++)
	{ 
		if(*(p+i)>='a'&&*(p+i)<='z')
			printf("%c",'a'+(*(p+i)-'a'+3)%26);
		else printf("%c",*(p+i));		
	}
	printf("\n");
	puts(a);
	return 0;
}
