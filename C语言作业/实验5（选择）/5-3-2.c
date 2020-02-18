#include <stdio.h>
int main()
{
	char c;
	scanf("%c",&c);
	if (c>='0' && c<='9')
	printf("0-9\n");
	else if (c>='A'&&c<='Z')
    printf("A-Z\n");
	else if(c>='a' && c<='z')
	printf("a-z\n");
	else
	printf("!,@,...\n");
	return 0;
}
