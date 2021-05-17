#include <iostream>
#include <cstdio>
#include <string>
#include <queue>
using namespace std;
string ans[26];//记录每个字母的编码 

typedef struct HTree//哈夫曼树结点 
{
	int weight;
	char letter;
	string s;
	HTree *Lchild=NULL,*Rchild=NULL;//注意初始化为空指针 
}HTree;

struct cmp//结点权值比较 
{
	bool operator()(HTree* &a,HTree* &b)
	{
		return a->weight>b->weight;
	}
};

void LevelOrderTraverse(HTree* T)//二叉树的层次遍历（广度优先遍历） 
{
	if(T==NULL) return;
	queue<HTree*> q;
	q.push(T);
	HTree *p=NULL;
	while(!q.empty())
	{
		p=q.front();
		q.pop();
		//cout<<p->weight<<endl;
		if(p->letter>='a'&&p->letter<='z')
			ans[p->letter-'a']=p->s;//记录字母对应的编码 
		if(p->Lchild)
		{
			p->Lchild->s=p->s+"0";//左子树为0 
			q.push(p->Lchild);
		}
		if(p->Rchild)
		{
			p->Rchild->s=p->s+"1";//右子树为1 
			q.push(p->Rchild);
		}
	}
}

/* 
void preorder(HTree* &t)//前序遍历打印二叉树 
{
	if(!t) return;
	cout<<t->letter<<endl;
	preorder(t->Lchild);
	preorder(t->Rchild);
}
*/

int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	priority_queue<HTree*,vector<HTree*>,cmp > q;//小顶堆，结点权值小的优先 
	int n,w;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>w;
		HTree *t=new HTree;
		t->weight=w;
		t->letter='a'+i;
		q.push(t);
	}
	for(int i=0;i<n-1;i++)
	{
		HTree *t=new HTree;
		HTree *a=q.top();
		q.pop();
		HTree *b=q.top();
		q.pop();
		t->Lchild=a;
		t->Rchild=b;
		t->weight=a->weight+b->weight;
		q.push(t);
	}//构造哈夫曼树 
	HTree *t=q.top();//最后剩下的一个结点即为哈夫曼树的根节点 
	//preorder(t);
	LevelOrderTraverse(t);//遍历哈夫曼树得到每个字母的编码 
	for(int i=0;i<n;i++)
	{
		char c='a'+i;
		cout<<c<<" "<<ans[i]<<endl;
	}//打印结果 
	return 0;
}

