#include <stdio.h>
#include "string.h"
int main()
{
	char a[200],b[200];
	int i,j=0,k,m,flag=1,s=0;
	gets(a);
	k=strlen(a);
	for(i=0;i<k;i++)
	{
		if(a[i]>='0'&&a[i]<='9') {b[j]=a[i];j++;}
		if(a[i]=='e') {m=i;break;}
	}
	for(i=m+1;i<k;i++)
	{
		if(a[i]='-') flag=2;
		if(a[i]>='0'&&a[i]<='9') s++;
	}
	if(flag==1)
	for(i=0;i<m;i++) printf("%d",a[i]);
	
	
	
}
