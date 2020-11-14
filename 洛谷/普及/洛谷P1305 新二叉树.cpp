#include <cstdio>
#include <iostream>
using namespace std;
struct node
{
	char c,l,r;
}tree[130];//二叉树 
void preorder(char c)
{
	printf("%c",c);
	if(tree[c].l!='*') preorder(tree[c].l);
	if(tree[c].r!='*') preorder(tree[c].r);
}//先序遍历 
int main()
{
	int t;
	char Tree;//树根 
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		char c,l,r;
		cin>>c>>l>>r;
		if(i==1) Tree=c;
		tree[c].l=l;
		tree[c].r=r;
	}
	preorder(Tree);
	return 0;
}
