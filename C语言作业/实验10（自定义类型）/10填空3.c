#include <stdio.h>
#include <malloc.h>
struct node
{  char data;
   struct node *link;
} *head;//headΪͷָ�� 
Ins(struct node *q)
{
   if(head==NULL)
   {   q->link=NULL;
       head=q;
   }
   else
   {   q->link=head;
       head=q;
   }
}//Ins�������������� 
main()
{   char ch;
struct node *p;
head=NULL;
while((ch=getchar())!='\n')
{
   p=(struct node *)malloc(sizeof(struct node)); 
   p->data=ch;
   Ins(p);
}//�������ַ������ַ��������������� 
p=head;//pָ��ָ�������ײ� 
while(p!=NULL)
{
   printf("%c",p->data);
   p=p->link;
}//��������������� 
}
