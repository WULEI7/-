#include <stdio.h>
#include <string.h>

int main()
{
	char a[1000],b[1000];
	int i,j=0,k,l;
	gets(a);
	k=strlen(a);
	for(i=0;i<k;i++)
	{
		if(a[i]=='-')
		{
			if((a[i-1]>='a'&&a[i-1]<='z'&&a[i+1]>='a'&&a[i+1]<='z')||(a[i-1]>='A'&&a[i-1]<='Z'&&a[i+1]>='A'&&a[i+1]<='Z')||(a[i-1]>='0'&&a[i-1]<='9'&&a[i+1]>='0'&&a[i+1]<='9'))
			{
				if(a[i-1]>=a[i+1]) break;
				for(l=0;l<a[i+1]-a[i-1]-1;l++)
					b[j++]=a[i-1]+l+1;
			}
			else b[j++]='-';
			continue;
		}
		else b[j++]=a[i];
	}
	for(i=0;i<j;i++)
		printf("%c",b[i]);
	return 0;
}
