#include <stdio.h>
#include <string.h>
int main()
{
	int n,i,b[1000],d,flag=0;
	char a[1000][10],c[10];
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		fflush(stdin);
		gets(a[i]);
		b[i]=strlen(a[i]);
	}
	fflush(stdin);
	gets(c);
	d=strlen(c);
	
	for(i=0;i<n;i++)
		if(a[i][0]==c[d-1])
		{
			flag++;
		}


}
