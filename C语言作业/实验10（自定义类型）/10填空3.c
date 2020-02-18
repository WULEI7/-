#include <stdio.h>
#include <malloc.h>
struct node
{  char data;
   struct node *link;
} *head;//head为头指针 
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
}//Ins函数逆序建立链表 
main()
{   char ch;
struct node *p;
head=NULL;
while((ch=getchar())!='\n')
{
   p=(struct node *)malloc(sizeof(struct node)); 
   p->data=ch;
   Ins(p);
}//按单个字符输入字符串并逆序建立链表 
p=head;//p指针指向链表首部 
while(p!=NULL)
{
   printf("%c",p->data);
   p=p->link;
}//正序输出整个链表 
}
