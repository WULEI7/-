#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector<int> ans[2];
struct node
{
	int key,pri;
	bool operator < (const node b) const
	{
		return key<b.key;
	}
}a[35];
struct tree
{
	int data[2];
	tree *lchild,*rchild;
};
tree* build(int L,int R)
{
	if(L>R)
		return NULL;
	int k,min=199999999;
	for(int i=L;i<=R;i++)
		if(a[i].pri<min)
		{
			k=i;
			min=a[i].pri;
		}
	tree *root=new tree;
	root->data[0]=a[k].key;
	root->data[1]=a[k].pri;
	root->lchild=build(L,k-1);
	root->rchild=build(k+1,R);
	return root;
}
void BFS(tree *root)
{
	queue<tree*> q;
	q.push(root);
	while(!q.empty())
	{
		tree* t=q.front();
		q.pop();
		ans[0].push_back(t->data[0]);
		ans[1].push_back(t->data[1]);
		if(t->lchild)
			q.push(t->lchild);
		if(t->rchild)
			q.push(t->rchild);
	}
}
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i].key>>a[i].pri;
	sort(a,a+n);
	//for(int i=0;i<n;i++)
	//	cout<<a[i].key<<" "<<a[i].pri<<endl;
	tree *root=build(0,n-1);
	BFS(root);
	int size=ans[0].size();
	cout<<ans[0][0];
	for(int i=1;i<size;i++)
		cout<<" "<<ans[0][i];
	cout<<endl<<ans[1][0];
	for(int i=1;i<size;i++)
		cout<<" "<<ans[1][i];
	return 0;
}
