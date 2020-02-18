#include <stdio.h>
#include <string.h>
int huiwen(char a[])
{
	int k,i,j,flag=1;
	k=strlen(a);
	for(i=0,j=k-1;i<j;i++,j--)
		if(a[i]!=a[j]) flag=0;
	if(flag==1) return 1;
	else return 0;
}
int main()
{
	char b[5][20];
	int i,sum=0;
	printf("Please input 5 strings:\n");
	for(i=0;i<5;i++)
		gets(b[i]);
	printf("Huiwens are :\n");
	for(i=0;i<5;i++)
		if(huiwen(b[i])==1)
		{
			sum++;
			puts(b[i]);
		}
	printf("num of Huiwens is :%d",sum);
	return 0;
}
