#include <stdio.h>
#include <stdlib.h>
#define N 5
struct student
{
	int XH;
	char XM[10];
	float CJ[3];
	float AVE;
}stu[N];

void main()
{
	int i;
	for(i=0;i<N;i++)
	{
		printf("Please input XH of No %d:\n",i+1);
		scanf("%d",&stu[i].XH);
		printf("Please input XM of No %d:\n",i+1);
		scanf("%s",stu[i].XM);
		printf("Please input CJ of No %d:\n",i+1);
		scanf("%f%f%f",&stu[i].CJ[0],&stu[i].CJ[1],&stu[i].CJ[2]);
		stu[i].AVE=(stu[i].CJ[0]+stu[i].CJ[1]+stu[i].CJ[2])/3;
	}
	
	FILE *fp;
	if((fp=fopen("stud","wt"))==NULL)
	{
		printf("cannot open the file stud!\n");
		exit(1);
	}
	for(i=0;i<N;i++)
	{
		if((fwrite(&stu[i],sizeof(struct student),1,fp))!=1)
			printf("flie write error!\n");
	}
	fclose(fp);
	
	if((fp=fopen("stud","rt"))==NULL)
	{
		printf("cannot open the file stud!\n");
		exit(1);
	}
	printf("the data:\n");
	printf("num name score1 score2 score3 average\n");
	for(i=0;i<N;i++)
	{
		fread(&stu[i],sizeof(struct student),1,fp);
		printf("%-2d%5s%7d%7d%7d%7.1f\n",stu[i].XH,stu[i].XM,(int)stu[i].CJ[0],(int)stu[i].CJ[1],(int)stu[i].CJ[2],stu[i].AVE);
	}
	fclose(fp);
}
