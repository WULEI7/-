#include <stdio.h>
int main()
{
	int n,a[20],b[100],i,j=1,s,flag,end;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(s=2;;)
	{
		flag=0; 
		for(i=0;i<n;i++)
			if(a[i]%s==0)
			{flag=1;a[i]/=s;}
		if(flag==1)
		{b[j]=s;j++;}
		else s++;
		end=1;
		for(i=0;i<n;i++)
			if(a[i]>1)
			{end=0;break;}
		if(end==1) break;
	}
	b[0]=0;
	for(i=1;i<j;i++)
		if(b[i]!=b[i-1])
			printf("%d ",b[i]);
	return 0;
}
