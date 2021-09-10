#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
int in[35],post[25];
vector<int> vec[35];
struct node
{
	int data;
	node *lchild,*rchild;
};
node* build(int postL,int postR,int inL,int inR)
{
	if(postL>postR)
		return NULL;
	node *root=new node;
	root->data=post[postR];
	int k;
	for(k=inL;k<=inR;k++)
		if(in[k]==post[postR])
			break;
	int num=k-inL;
	root->lchild=build(postL,postL+num-1,inL,k-1);
	root->rchild=build(postL+num,postR-1,k+1,inR);
	return root;
}//�ݹ齨������ 
void BFS(node* root)
{
	cout<<root->data;//������ڵ��ֵ 
	queue<node*> q;
	q.push(root);
	int level=0;//��ǰ���������ڵ�Ϊ��1�㣩 
	while(!q.empty())
	{
		level++;
		int size=q.size();//��ǰ���ϵĽ����� 
		while(size--)
		{
			node* t=q.front();
			q.pop();
			vec[level].emplace_back(t->data);
			if(t->lchild)
				q.push(t->lchild);
			if(t->rchild)
				q.push(t->rchild);
		}
	}
	for(int i=2;i<=level;i++)
	{
		if(i%2==0)//ż�������������� 
		{
			for(int j=0;j<vec[i].size();j++)
				cout<<" "<<vec[i][j];
		}
		else//���������������� 
		{
			for(int j=vec[i].size()-1;j>=0;j--)
				cout<<" "<<vec[i][j];
		}
	}
}//������������ 
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>in[i];
	for(int i=0;i<n;i++)
		cin>>post[i];
	node *root=build(0,n-1,0,n-1);
	BFS(root);
	return 0; 
}
