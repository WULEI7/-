#include <stdio.h>
#include <malloc.h>
struct Link
{
	int data;
	struct Link *next;
};
void InsertList(struct Link*H,int n)
{
	struct Link*p;
	p=H;
	while(p->next!=NULL)
	{
		p=p->next;
	}
	p->next=(struct Link*)malloc(sizeof(struct Link));
	p=p->next;
	p->data=n;
	p->next=NULL;
}//注意insert操作的写法 
int main()
{
	int a[]={5,10,15};
	int b[]={1,4,6,8,30,45};
	struct Link *H,*p;
	H=(struct Link*)malloc(sizeof(struct Link));
	H->next=NULL;
	int flag=0;
	int i,j=0,t=0;
	for(i=1;i<=6;i++)
	{
		if(flag==0) 
		{
			InsertList(H,a[j]);
			j++;
			flag=1;
			continue; 
		}
		if(flag==1)
		{
			InsertList(H,b[t]);
			t++;
			flag=0;continue;
		}
	}
	for(i=7;i<=9;i++)
	{
		InsertList(H,b[t]);
		t++;
	}
	p=H->next;//头结点不存值，从H->next结点开始输出 
	while(p)
	{
		printf("%4d",p->data);
		p=p->next;
	}
	
}
