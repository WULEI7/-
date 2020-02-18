#include <stdio.h>
#include <stdlib.h>
void main()
{
	FILE *fp;
	int a[100],i,j=0,sump=0,sumn=0;
	if((fp=fopen("file11_1.txt","rt"))==NULL)
	{
		printf("cannot open file");
		exit(1);
	}
	while(!feof(fp))
	{
		fscanf(fp,"%d",&a[j]);
		j++;
	}
	fclose(fp);
	for(i=0;i<j;i++)
	{
		if(a[i]>0) sump+=a[i];
		if(a[i]<0) sumn+=a[i];
	}
	printf("sum>0 number is %d,sum<0 number is %d",sump,sumn);
}
