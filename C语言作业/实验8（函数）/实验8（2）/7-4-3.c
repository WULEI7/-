#include <stdio.h>
#include <string.h>
int main()
{
	char a[81],b;
	int i,j,k,n=0;
	printf("Please input a string(length<=80):\n");
	gets(a);
	k=strlen(a);
	printf("Please input a char to be deleted:\n");
	scanf("%c",&b);
	for(i=0;i<k;i++)
	{	
		if(a[i]==b)
		{
			n++;
			for(j=i;j<k;j++)
				a[j]=a[j+1];
			i--;
			k--;
		}
	
	}
	a[k]='\0';
	puts(a);
	return 0;
} 
