#include<stdio.h>
int main()
{
	char n;
	int i;
	printf("input a character(A~Z):\n");
	scanf("%c",&n);
	i = (n-67+26)%26;
	printf("%c->%c",n,i+65);
	return 0;
} 
