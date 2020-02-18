#include <stdio.h>
#include <string.h>
int main()
{
	int n,i,k;
	char a[51];
	scanf("%d",&n);
	scanf("%s",a);
	k=strlen(a);
	for(i=0;i<k;i++)
		a[i]='a'+(a[i]-'a'+n)%26;
	puts(a);
	return 0;
}
