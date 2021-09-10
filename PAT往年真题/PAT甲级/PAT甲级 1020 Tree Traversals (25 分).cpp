#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
int post[35],in[35];
struct node
{
	int data;
	node *lchild,*rchild;
};
node* build(int postL,int postR,int inL,int inR)
{
	if(postL>postR)
		return NULL;
	node* root=new node;
	root->data=post[postR];
	int k;
	for(k=inL;k<=inR;k++)
		if(in[k]==post[postR])
			break;
	int num=k-inL;
	root->lchild=build(postL,postL+num-1,inL,k-1);
	root->rchild=build(postL+num,postR-1,k+1,inR);
	return root;
}//µÝ¹é½¨¶þ²æÊ÷ 
void BFS(node* root)
{
	int d=root->data;
	queue<node*> q;
	q.push(root);
	while(!q.empty())
	{
		node* t=q.front();
		q.pop();
		if(t->data==d)
			cout<<d;
		else
			cout<<" "<<t->data;
		if(t->lchild)
			q.push(t->lchild);
		if(t->rchild)
			q.push(t->rchild);
	}
}//²ãÐò±éÀú 
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>post[i];
	for(int i=0;i<n;i++)
		cin>>in[i];
	node* root=build(0,n-1,0,n-1);
	BFS(root);
	return 0;
	return 0; 
}
