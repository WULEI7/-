#include <stdio.h>
int main()
{
	char a[20][101],b[101][26];
	int i,j,k,t,cd=0,s[26]={0},max=0;
	while(scanf("%d",a[cd])!=EOF)//输入ctrl+z停止 
	{
		gets(a[cd]);cd++;
	}
	
	for(i=0;i<cd;i++)
		for(j=0;a[i][j]!='\0';j++)
			if(a[i][j]>='a'&&a[i][j]<='z') s[a[i][j]-'a']++;//统计每个小写字母的数量 
	
	for(i=0;i<26;i++)
		if(s[i]>max) max=s[i];//得到数量的最大值，即输出柱状图的最高点 
		
	for(i=0;i<25;i++)
		for(j=i+1;j<26;j++)
			if(s[i]<s[j])
			{t=s[i];s[i]=s[j];s[j]=t;}//按字母数量从多到少选择排序 
	
	for(k=0;k<26;k++)
		for(i=max-s[k];i<max;i++)
			b[i][k]='#';
	for(i=0;i<max;i++)
		for(j=0;j<26;j++)
			if(b[i][j]!='#') b[i][j]=' ';//填入#号，空余部分用空格填充 
			
	for(i=0;i<max;i++)
	{
		for(j=0;j<26;j++)
		printf("%c",b[i][j]);
		if(s[j]==0) break;
		printf("\n"); 
	}//输出柱状图 
	return 0;
}
