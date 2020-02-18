#include <stdio.h>
int main()
{
	char a[4][101],b[101][51];
	int i,j,k,s[26]={0},max=0;
	for(i=0;i<101;i++)
		for(j=0;j<51;j++)
			b[i][j]=' ';
	
	for(i=0;i<4;i++)
		gets(a[i]);
	for(i=0;i<4;i++)
		for(j=0;a[i][j]!='\0';j++)
			if(a[i][j]>='A'&&a[i][j]<='Z') s[a[i][j]-'A']++;
	for(i=0;i<26;i++)
		if(s[i]>max) max=s[i];
	for(k=0;k<26;k++)
		for(i=max-s[k];i<max;i++)
			b[i][2*k]='*';
	
	for(i=0;i<max;i++)
	{
		for(j=0;j<=50;j++)
		printf("%c",b[i][j]);
		printf("\n");
	}
	printf("A B C D E F G H I J K L M N O P Q R S T U V W X Y Z");
	return 0;
}
