#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

typedef struct BitNode//二叉树 
{
	char data;
	BitNode *Lchild,*Rchild;
}BitNode,*BiTree;

void CreateBiTree(BiTree &T)//建立二叉树：按先序次序输入二叉树中结点的值（字符），“#”表示空树 
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

void CopyBiTree(BiTree &S,BiTree T)//二叉树的复制 
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

void ChangeBiTree(BiTree T)//交换左右子树 
{
	if(T==NULL) return;
	BiTree temp=T->Lchild;
	T->Lchild=T->Rchild;
	T->Rchild=temp;
	ChangeBiTree(T->Lchild);
	ChangeBiTree(T->Rchild);
}

int IsSame(BiTree S,BiTree T)//判断两棵二叉树是否相同 
{
	if(S==NULL&&T==NULL)//两棵树都为空 
		return 1;
	if(S==NULL&&T!=NULL||S!=NULL&T==NULL)//一棵树为空一棵树不为空 
		return 0;
	if(S->data!=T->data)//结点的值不同 
		return 0;
	return IsSame(S->Lchild,T->Lchild)&&IsSame(S->Rchild,T->Rchild);//继续判断它们的左右子树是否相同 
}

int Depth(BiTree T)//求二叉树的深度 
{
	if(T==NULL) return 0;
	int l=Depth(T->Lchild);
	int r=Depth(T->Rchild);
	return l>r?l+1:r+1;
}

int Width(BiTree T)//求二叉树的宽度（每层结点数的最大值） 
{
	if(T==NULL) return 0;
	int maxn=1;//每层结点数的最大值 
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

int Leafcnt(BiTree T)//求叶子结点数量 
{
	if(T==NULL) return 0;
	int l=Leafcnt(T->Lchild);
	int r=Leafcnt(T->Rchild);
	if(T->Lchild==NULL&&T->Rchild==NULL)
		return l+r+1;
	return l+r; 
}

void PreOrderTraverse(BiTree T)//先序遍历（递归） 
{
	if(T==NULL) return;
	cout<<T->data;
	PreOrderTraverse(T->Lchild);
	PreOrderTraverse(T->Rchild);
}

void InOrderTraverse(BiTree T)//中序遍历（递归） 
{
	if(T==NULL) return;
	InOrderTraverse(T->Lchild);
	cout<<T->data;
	InOrderTraverse(T->Rchild);
}

void PostOrderTraverse(BiTree T)//后序遍历（递归） 
{
	if(T==NULL) return;
	PostOrderTraverse(T->Lchild);
	PostOrderTraverse(T->Rchild);
	cout<<T->data;
}

void PreOrderTraverse_(BiTree T)//先序遍历（非递归） 
{
	if(T==NULL) return;
	stack<BiTree> s;
	BiTree p=NULL;
	s.push(T);
	while(!s.empty())
	{
		p=s.top();
		s.pop();
		cout<<p->data;//出栈结点并访问 
		if(p->Rchild)
			s.push(p->Rchild);//访问左子树 
		if(p->Lchild)
			s.push(p->Lchild);//访问右子树 
	}
}

void InOrderTraverse_(BiTree T)//中序遍历（非递归） 
{
	if(T==NULL) return;
	stack<BiTree> s;
	BiTree p=T;
	while(p!=NULL||!s.empty())
	{
		if(p!=NULL)
		{
			s.push(p);
			p=p->Lchild;//访问左子树 
		}
		else
		{
			p=s.top();
			s.pop();
			cout<<p->data;
			p=p->Rchild;//访问右子树 
		}
	}
}

void PostOrderTraverse_(BiTree T)//后序遍历（非递归） 
{
	if(T==NULL) return;
	stack<BiTree> s;
	BiTree pre=NULL,cur=NULL;
	s.push(T);//根节点入栈 
	while(!s.empty())
	{
		cur=s.top();
		if((cur->Lchild==NULL&&cur->Rchild==NULL)//不存在左右子树 
		  ||pre!=NULL&&(pre==cur->Lchild||pre==cur->Rchild))//或左右子树都已访问过 
		{
			s.pop();
			cout<<cur->data;
			pre=cur;
		}
		else
		{
			if(cur->Rchild!=NULL)
				s.push(cur->Rchild);//右子树入栈 
			if(cur->Lchild!=NULL)
				s.push(cur->Lchild);//左子树入栈 
		}
	}
}

void LevelOrderTraverse(BiTree T)//层次遍历（广度优先遍历） 
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
	BiTree T;//二叉树根节点 
	cout<<"请按照序次序输入二叉树，空结点用#表示："<<endl; 
	CreateBiTree(T);//建立二叉树：按先序次序输入二叉树中结点的值（字符），“#”表示空树 
	cout<<"二叉树的先序遍历："<<endl;
	cout<<"递归实现：  ";
	PreOrderTraverse(T);
	cout<<endl;
	cout<<"非递归实现：";
	PreOrderTraverse_(T);
	cout<<endl;
	cout<<"二叉树的中序遍历："<<endl;
	cout<<"递归实现：  ";
	InOrderTraverse(T);
	cout<<endl;
	cout<<"非递归实现：";
	InOrderTraverse_(T);
	cout<<endl;
	cout<<"二叉树的后序遍历："<<endl;
	cout<<"递归实现：  ";
	PostOrderTraverse(T);
	cout<<endl;
	cout<<"非递归实现：";
	PostOrderTraverse_(T);
	cout<<endl;
	cout<<"二叉树的层次遍历：";
	LevelOrderTraverse(T);
	cout<<endl;
	cout<<"二叉树T的深度为：";
	cout<<Depth(T)<<endl;
	cout<<"二叉树T的宽度为：";
	cout<<Width(T)<<endl;
	cout<<"二叉树T的叶子结点数量为：";
	cout<<Leafcnt(T)<<endl; 
	cout<<"将二叉树T复制到新二叉树S"<<endl;
	cout<<"新二叉树S的层次遍历：";
	BiTree S;
	CopyBiTree(S,T);
	LevelOrderTraverse(S);
	cout<<endl;
	cout<<"二叉树T和S是否相同：";
	cout<<IsSame(T,S)<<endl;
	cout<<"交换二叉树T的左右子树"<<endl;
	ChangeBiTree(T);
	cout<<"交换左右子树后的层次遍历：";
	LevelOrderTraverse(T);
	cout<<endl;
	cout<<"二叉树T和S是否相同：";
	cout<<IsSame(T,S)<<endl;
	return 0;
}
/*
	测试数据：
	1  ABDF##G##E##C##
	2  ABC##DE#G##F###
	3  ABD##E##C#F##
*/
