#include <iostream>
#include <cstdio>
#include <string>
#include <queue>
using namespace std;
string ans[26];//��¼ÿ����ĸ�ı��� 

typedef struct HTree//����������� 
{
	int weight;
	char letter;
	string s;
	HTree *Lchild=NULL,*Rchild=NULL;//ע���ʼ��Ϊ��ָ�� 
}HTree;

struct cmp//���Ȩֵ�Ƚ� 
{
	bool operator()(HTree* &a,HTree* &b)
	{
		return a->weight>b->weight;
	}
};

void LevelOrderTraverse(HTree* T)//�������Ĳ�α�����������ȱ����� 
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
			ans[p->letter-'a']=p->s;//��¼��ĸ��Ӧ�ı��� 
		if(p->Lchild)
		{
			p->Lchild->s=p->s+"0";//������Ϊ0 
			q.push(p->Lchild);
		}
		if(p->Rchild)
		{
			p->Rchild->s=p->s+"1";//������Ϊ1 
			q.push(p->Rchild);
		}
	}
}

/* 
void preorder(HTree* &t)//ǰ�������ӡ������ 
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
	priority_queue<HTree*,vector<HTree*>,cmp > q;//С���ѣ����ȨֵС������ 
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
	}//����������� 
	HTree *t=q.top();//���ʣ�µ�һ����㼴Ϊ���������ĸ��ڵ� 
	//preorder(t);
	LevelOrderTraverse(t);//�������������õ�ÿ����ĸ�ı��� 
	for(int i=0;i<n;i++)
	{
		char c='a'+i;
		cout<<c<<" "<<ans[i]<<endl;
	}//��ӡ��� 
	return 0;
}

