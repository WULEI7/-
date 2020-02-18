#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void main()
{
	FILE *fp;
	char filename1[100],filename2[100];
	char str[100],ch;
	int i,j=0;
	printf("Please input a source text file's name:\n");
	gets(filename1);
	printf("Please input a destination text file's name:\n");
	gets(filename2);
	
	printf("Here is the destination text file's content:\n");
	if((fp=fopen("filename2","rt"))==NULL)
	{
		printf("cannot open file");
		exit(1);
	}
	ch=fgetc(fp);
	while(ch!=EOF)
	{
		putchar(ch);
		ch=fgetc(fp);
	}
	fclose(fp);
	
	printf("Here is the source text file's content:\n");
	if((fp=fopen("filename1","rt"))==NULL)
	{
		printf("cannot open file");
		exit(1);
	}
	ch=fgetc(fp);
	while(ch!=EOF)
	{
		str[j]=ch;
		ch=fgetc(fp);
		j++;
	}
	for(i=0;i<j;i++)
		printf("%c",str[i]);
	fclose(fp);
	
	if((fp=fopen("filename2","at"))==NULL)
	{
		printf("cannot open file");
		exit(1);
	}
	for(i=0;i<j;i++)
		fputc(str[i],fp);
	fclose(fp);
	
	printf("Here is the new destination text file's content:\n");
	if((fp=fopen("filename2","rt"))==NULL)
	{
		printf("cannot open file");
		exit(1);
	}
	ch=fgetc(fp);
	while(ch!=EOF)
	{
		putchar(ch);
		ch=fgetc(fp);
	}
	fclose(fp);
}
