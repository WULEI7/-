#include <stdio.h>
#define n 5
struct student
{
	int numb;
	char name[20];
	int Math;
	int Engl;
	int Clan;
};
void main()
{
	int i;
	struct student stu[n];
	struct student *p=stu;
	for(i=0;i<n;i++,p++)
		scanf("%d %s %d %d %d",&(p->numb),p->name,&(p->Math),&(p->Engl),&(p->Clan));
	p=stu;
	struct student *max=stu,*min=stu;
	int a[n];
	for(i=0;i<n;i++)
		a[i]=(p+i)->Math+(p+i)->Engl+(p+i)->Clan;
	int tmax,tmin;
	tmax=tmin=a[0];
	for(i=0;i<n;i++)
	{
		if(a[i]>tmax)
			{tmax=a[i];max=p+i;}
		if(a[i]<tmin)
			{tmin=a[i];min=p+i;}
	}
	printf("The max total score's student is %d  %s  %d\n",max->numb,max->name,tmax);
	printf("The min total score's student is %d  %s  %d\n",min->numb,min->name,tmin);
}
