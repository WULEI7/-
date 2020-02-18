#include <stdio.h>
#include <string.h>
int main()
{
	char a[15],b[1000001],c[15];
	int n,i,j,k,ch0,ch,wz,flag=1,sum=0;
	gets(a);
	ch0=strlen(a);
	for(i=0;i<ch0;i++)
		if(a[i]>='A'&&a[i]<='Z') a[i]+=32;//数组a输入目标单词并转换成小写字母
	gets(b);
	ch=strlen(b);
	for(i=0;i<ch;i++)
		if(b[i]>='A'&&b[i]<='Z') b[i]+=32;//数组b输入整篇文章并转换成小写字母
	
	for(n=0;n<ch;)
	{
		if(b[n]==' ') {n+=1;continue;}
		for(i=0,j=n,k=0;b[j]!=' '&&j<ch;i++,j++,k++)
			c[k]=b[j];
		if(strcmp(a,c)!=0) flag=0;
		if(flag==1) sum++;
		if(flag==1&&sum==1) wz=n;
		n+=i;
		for(k=0;k<15;k++)
			c[k]='\0'; 
		flag=1;
	}//文章从头到尾，将每个单词存入数组c，并与目标单词比较，得到结果后清空数组c 
	if(sum==0) printf("-1");
	else printf("%d %d",sum,wz);
	return 0;
}
