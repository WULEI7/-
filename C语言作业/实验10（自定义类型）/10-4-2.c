#include <stdio.h>
#include <malloc.h>
#define LEN sizeof(struct node)
struct node
{
	int num;
	struct node *next;
};
struct node *create(int n,int a[])
{
	struct node *head=NULL,*pf,*pb;
	int i;
	for(i=0;i<n;i++) 
	{
		pb=(struct node *)malloc(LEN);
		pb->num=a[i];
		if(i==0) pf=head=pb;
		else pf->next=pb;
		pb->next=NULL;
		pf=pb;
	}
	return (head);
}

void main()
{
	int a[]={5,10,15},b[]={1,4,6,8,30,45};
	int len1=sizeof(a)/sizeof(a[0]),len2=sizeof(b)/sizeof(b[0]);
	struct node *head1,*head2,*p,*q,*r,*s;
	head1=create(len1,a);
	head2=create(len2,b);//将a，b数组分别存入两个链表 
	
	p=q=head1;r=s=head2;
	while(p->next!=NULL)
	{
	q=q->next;
	p->next=r;
	s=s->next;
	p=q;
	r->next=p;
	r=s;
	}
	p->next=r;
	s=s->next;//完成新链表的连接 
	
	p=head1;
	while(p!=NULL)
	{
		printf("%5d",p->num);
		p=p->next;
	}//输出新链表 
}
