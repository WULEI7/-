#include <stdio.h>
int main()
{
	char a[20][101],b[101][26];
	int i,j,k,t,cd=0,s[26]={0},max=0;
	while(scanf("%d",a[cd])!=EOF)//����ctrl+zֹͣ 
	{
		gets(a[cd]);cd++;
	}
	
	for(i=0;i<cd;i++)
		for(j=0;a[i][j]!='\0';j++)
			if(a[i][j]>='a'&&a[i][j]<='z') s[a[i][j]-'a']++;//ͳ��ÿ��Сд��ĸ������ 
	
	for(i=0;i<26;i++)
		if(s[i]>max) max=s[i];//�õ����������ֵ���������״ͼ����ߵ� 
		
	for(i=0;i<25;i++)
		for(j=i+1;j<26;j++)
			if(s[i]<s[j])
			{t=s[i];s[i]=s[j];s[j]=t;}//����ĸ�����Ӷൽ��ѡ������ 
	
	for(k=0;k<26;k++)
		for(i=max-s[k];i<max;i++)
			b[i][k]='#';
	for(i=0;i<max;i++)
		for(j=0;j<26;j++)
			if(b[i][j]!='#') b[i][j]=' ';//����#�ţ����ಿ���ÿո���� 
			
	for(i=0;i<max;i++)
	{
		for(j=0;j<26;j++)
		printf("%c",b[i][j]);
		if(s[j]==0) break;
		printf("\n"); 
	}//�����״ͼ 
	return 0;
}
