#include <stdio.h>
#include <string.h>
int main()
{
	char a[22];
	int i,n,k,wz,sort=0,flag;
	gets(a);
	k=strlen(a);
	for(i=0;i<k;i++)
	{
		if(a[i]=='.') {sort=1;wz=i;}
		if(a[i]=='/') {sort=2;wz=i;}
		if(a[i]=='%') sort=3;
	}
	if(sort==0||sort==3)
	{
		for(i=k-1;i>=0;i--)
			if(a[i]!='0'&&a[i]!='%')
				{n=i;break;}
		for(i=n;i>=0;i--)
			printf("%c",a[i]);
		if(sort==3) printf("%%");
	}//整数&百分数 
	if(sort==1)
	{
		for(i=wz-1;i>=0;i--)
			if(a[i]!='0') 
				{n=i;break;}
		for(i=n;i>=0;i--)
			printf("%c",a[i]);
		printf(".");
		flag=1;
		for(i=wz+1;i<k;i++)
			if(a[i]!='0')
				{n=i;flag=0;break;}
		if(flag==0)
			for(i=k-1;i>=n;i--)
				printf("%c",a[i]);
		else printf("0");
	}//小数 
	if(sort==2)
	{
		for(i=wz-1;i>=0;i--)
			if(a[i]!='0')
				{n=i;break;}
		for(i=n;i>=0;i--)
			printf("%c",a[i]);
		printf("/");
		for(i=k-1;i>wz;i--)
			if(a[i]!='0')
				{n=i;break;}
		for(i=n;i>wz;i--)
			printf("%c",a[i]);
	}//分数
	return 0;
}
