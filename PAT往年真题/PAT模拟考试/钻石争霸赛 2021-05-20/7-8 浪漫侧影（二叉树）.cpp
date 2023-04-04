#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
int n,in[25],post[25];//二叉树的中序和后序遍历 
int level=0;//二叉树层数 
vector<int> tree[25];//二叉树的层序遍历 
struct node//二叉树结点 
{
	int num;
	node *lchild,*rchild;
};
node* build(int postL,int postR,int inL,int inR)//递归建树 
{
	if(postL>postR)
		return NULL;
	node *root=new node;
	root->num=post[postR];
	int k=0;
	for(k=inL;k<=inR;k++)
		if(in[k]==post[postR])
			break;
	int num=k-inL;
	root->lchild=build(postL,postL+num-1,inL,k-1);
	root->rchild=build(postL+num,postR-1,k+1,inR);
	return root;
}
void BFS(node* root)//层序遍历 
{
	queue<node*> q;
	q.push(root);
	while(!q.empty())
	{
		level++;//当前层数 
		//cout<<level<<endl;
		int size=q.size();
		while(size--)
		{
			node *t=q.front();
			q.pop();
			tree[level].emplace_back(t->num);
			if(t->lchild) q.push(t->lchild);
			if(t->rchild) q.push(t->rchild);
		}
	}
	return;
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>in[i];
	for(int i=1;i<=n;i++)
		cin>>post[i];
	node *root=build(1,n,1,n);
	BFS(root);
	/*
	for(int i=1;i<=level;i++)
	{
		int size=tree[i].size();
		for(int j=0;j<size;j++)
			cout<<tree[i][j]<<" ";
		cout<<endl;
	}
	*/
	cout<<"R:";
	for(int i=1;i<=level;i++)
		cout<<" "<<tree[i][tree[i].size()-1];
	cout<<endl;
	cout<<"L:";
	for(int i=1;i<=level;i++)
		cout<<" "<<tree[i][0];
	cout<<endl;
	return 0;
}
