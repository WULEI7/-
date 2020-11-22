#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

typedef struct BitNode//������ 
{
	char data;
	BitNode *Lchild,*Rchild;
}BitNode,*BiTree;

void CreateBiTree(BiTree &T)//�������������������������������н���ֵ���ַ�������#����ʾ���� 
{
	char ch;
	cin>>ch;
	if(ch=='#') T=NULL;
	else
	{
		T=new BitNode;
		T->data=ch;
		CreateBiTree(T->Lchild);
		CreateBiTree(T->Rchild);
	}
}

void CopyBiTree(BiTree &S,BiTree T)//�������ĸ��� 
{
	if(T==NULL)
	{
		S=NULL;
		return;
	}
	S=new BitNode;
	S->data=T->data;
	CopyBiTree(S->Lchild,T->Lchild);
	CopyBiTree(S->Rchild,T->Rchild);
}

void ChangeBiTree(BiTree T)//������������ 
{
	if(T==NULL) return;
	BiTree temp=T->Lchild;
	T->Lchild=T->Rchild;
	T->Rchild=temp;
	ChangeBiTree(T->Lchild);
	ChangeBiTree(T->Rchild);
}

int IsSame(BiTree S,BiTree T)//�ж����ö������Ƿ���ͬ 
{
	if(S==NULL&&T==NULL)//��������Ϊ�� 
		return 1;
	if(S==NULL&&T!=NULL||S!=NULL&T==NULL)//һ����Ϊ��һ������Ϊ�� 
		return 0;
	if(S->data!=T->data)//����ֵ��ͬ 
		return 0;
	return IsSame(S->Lchild,T->Lchild)&&IsSame(S->Rchild,T->Rchild);//�����ж����ǵ����������Ƿ���ͬ 
}

int Depth(BiTree T)//������������ 
{
	if(T==NULL) return 0;
	int l=Depth(T->Lchild);
	int r=Depth(T->Rchild);
	return l>r?l+1:r+1;
}

int Width(BiTree T)//��������Ŀ�ȣ�ÿ�����������ֵ�� 
{
	if(T==NULL) return 0;
	int maxn=1;//ÿ�����������ֵ 
	queue<BiTree> q;
	q.push(T);
	BiTree p=NULL;
	while(1)
	{
		int size=q.size();
		if(size==0) break;
		while(size>0)
		{
			p=q.front();
			q.pop();
			size--;
			if(p->Lchild)
				q.push(p->Lchild);
			if(p->Rchild)
				q.push(p->Rchild);
		}
		size=q.size();
		maxn=max(maxn,size);
	}
	return maxn;
}

int Leafcnt(BiTree T)//��Ҷ�ӽ������ 
{
	if(T==NULL) return 0;
	int l=Leafcnt(T->Lchild);
	int r=Leafcnt(T->Rchild);
	if(T->Lchild==NULL&&T->Rchild==NULL)
		return l+r+1;
	return l+r; 
}

void PreOrderTraverse(BiTree T)//����������ݹ飩 
{
	if(T==NULL) return;
	cout<<T->data;
	PreOrderTraverse(T->Lchild);
	PreOrderTraverse(T->Rchild);
}

void InOrderTraverse(BiTree T)//����������ݹ飩 
{
	if(T==NULL) return;
	InOrderTraverse(T->Lchild);
	cout<<T->data;
	InOrderTraverse(T->Rchild);
}

void PostOrderTraverse(BiTree T)//����������ݹ飩 
{
	if(T==NULL) return;
	PostOrderTraverse(T->Lchild);
	PostOrderTraverse(T->Rchild);
	cout<<T->data;
}

void PreOrderTraverse_(BiTree T)//����������ǵݹ飩 
{
	if(T==NULL) return;
	stack<BiTree> s;
	BiTree p=NULL;
	s.push(T);
	while(!s.empty())
	{
		p=s.top();
		s.pop();
		cout<<p->data;//��ջ��㲢���� 
		if(p->Rchild)
			s.push(p->Rchild);//���������� 
		if(p->Lchild)
			s.push(p->Lchild);//���������� 
	}
}

void InOrderTraverse_(BiTree T)//����������ǵݹ飩 
{
	if(T==NULL) return;
	stack<BiTree> s;
	BiTree p=T;
	while(p!=NULL||!s.empty())
	{
		if(p!=NULL)
		{
			s.push(p);
			p=p->Lchild;//���������� 
		}
		else
		{
			p=s.top();
			s.pop();
			cout<<p->data;
			p=p->Rchild;//���������� 
		}
	}
}

void PostOrderTraverse_(BiTree T)//����������ǵݹ飩 
{
	if(T==NULL) return;
	stack<BiTree> s;
	BiTree pre=NULL,cur=NULL;
	s.push(T);//���ڵ���ջ 
	while(!s.empty())
	{
		cur=s.top();
		if((cur->Lchild==NULL&&cur->Rchild==NULL)//�������������� 
		  ||pre!=NULL&&(pre==cur->Lchild||pre==cur->Rchild))//�������������ѷ��ʹ� 
		{
			s.pop();
			cout<<cur->data;
			pre=cur;
		}
		else
		{
			if(cur->Rchild!=NULL)
				s.push(cur->Rchild);//��������ջ 
			if(cur->Lchild!=NULL)
				s.push(cur->Lchild);//��������ջ 
		}
	}
}

void LevelOrderTraverse(BiTree T)//��α�����������ȱ����� 
{
	if(T==NULL) return;
	queue<BiTree> q;
	q.push(T);
	BiTree p=NULL;
	while(!q.empty())
	{
		p=q.front();
		q.pop();
		cout<<p->data;
		if(p->Lchild)
			q.push(p->Lchild);
		if(p->Rchild)
			q.push(p->Rchild);
	}
}


int main()
{
	BiTree T;//���������ڵ� 
	cout<<"�밴�������������������ս����#��ʾ��"<<endl; 
	CreateBiTree(T);//�������������������������������н���ֵ���ַ�������#����ʾ���� 
	cout<<"�����������������"<<endl;
	cout<<"�ݹ�ʵ�֣�  ";
	PreOrderTraverse(T);
	cout<<endl;
	cout<<"�ǵݹ�ʵ�֣�";
	PreOrderTraverse_(T);
	cout<<endl;
	cout<<"�����������������"<<endl;
	cout<<"�ݹ�ʵ�֣�  ";
	InOrderTraverse(T);
	cout<<endl;
	cout<<"�ǵݹ�ʵ�֣�";
	InOrderTraverse_(T);
	cout<<endl;
	cout<<"�������ĺ��������"<<endl;
	cout<<"�ݹ�ʵ�֣�  ";
	PostOrderTraverse(T);
	cout<<endl;
	cout<<"�ǵݹ�ʵ�֣�";
	PostOrderTraverse_(T);
	cout<<endl;
	cout<<"�������Ĳ�α�����";
	LevelOrderTraverse(T);
	cout<<endl;
	cout<<"������T�����Ϊ��";
	cout<<Depth(T)<<endl;
	cout<<"������T�Ŀ��Ϊ��";
	cout<<Width(T)<<endl;
	cout<<"������T��Ҷ�ӽ������Ϊ��";
	cout<<Leafcnt(T)<<endl; 
	cout<<"��������T���Ƶ��¶�����S"<<endl;
	cout<<"�¶�����S�Ĳ�α�����";
	BiTree S;
	CopyBiTree(S,T);
	LevelOrderTraverse(S);
	cout<<endl;
	cout<<"������T��S�Ƿ���ͬ��";
	cout<<IsSame(T,S)<<endl;
	cout<<"����������T����������"<<endl;
	ChangeBiTree(T);
	cout<<"��������������Ĳ�α�����";
	LevelOrderTraverse(T);
	cout<<endl;
	cout<<"������T��S�Ƿ���ͬ��";
	cout<<IsSame(T,S)<<endl;
	return 0;
}
/*
	�������ݣ�
	1  ABDF##G##E##C##
	2  ABC##DE#G##F###
	3  ABD##E##C#F##
*/
