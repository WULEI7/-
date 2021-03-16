#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;

typedef struct
{
	int weight;
	int parent;
	int lchild;
	int rchild;
}HTNode,*HuffmanTree;//动态分配数组存储哈夫曼树 
typedef char** HuffmanCode;//动态分配数组存储哈夫曼编码表 

void Select(HuffmanTree &HT,int num,int &child1,int &child2)//注意Select函数的写法 
{
	int w1=1999999999,w2=1999999999;
	for(int i=1;i<=num;i++)
		if(HT[i].parent==0&&w1>HT[i].weight)
		{
			child1=i;
			w1=HT[i].weight;
			continue;
		}
	for(int i=1;i<=num;i++)
		if(HT[i].parent==0&&w2>HT[i].weight&&i!=child1)
		{
			child2=i;
			w2=HT[i].weight;
			continue;
		}
	//以上才是正确的Select写法，目的是使构造的哈夫曼树具有相同的结构 
	//之前做数据结构作业的时候写法如下，有小部分数据可能会出错，在蓝桥杯OJ上只能拿到90分 
	/* 
	child1=0;child2=0;
	int w1,w2;
	for(int i=1;i<=num;i++)
	{
		if(HT[i].parent==0)
		{
			if(child1==0||w1>=w2&&w1>=HT[i].weight)
			{
				child1=i;
				w1=HT[i].weight;
				continue;
			}
			if(child2==0||w2>=w1&&w2>=HT[i].weight)
			{
				child2=i;
				w2=HT[i].weight;
				continue;
			}
		}
	}
	*/
}//在HT[1]-HT[num]中选择parent为0且weight最小的两个结点，其序号分别为s1和s2 

void HuffmanCoding(HuffmanTree &HT,HuffmanCode &HC,int w[],int n)
{
	int child1,child2;
	if(n<=1) return;
	int m=n*2-1;
	HT=(HuffmanTree)malloc((m+1)*sizeof(HTNode));
	for(int i=1;i<=n;i++)
		HT[i]={w[i-1],0,0,0};
	for(int i=n+1;i<=m;i++)
		HT[i]={0,0,0,0};
	for(int i=n+1;i<=m;i++)
	{
		Select(HT,i-1,child1,child2);
		HT[child1].parent=i;
		HT[child2].parent=i;
		HT[i].lchild=child1;
		HT[i].rchild=child2;
		HT[i].weight=HT[child1].weight+HT[child2].weight;
	}//建哈夫曼树 
	/* 
	HC=(HuffmanCode)malloc((n+1)*sizeof(char *));
	char* cd=(char *)malloc(n*sizeof(char));
	cd[n-1]='\0';
	for(int i=1;i<=n;i++)
	{
		int pos=n-1;
		for(int c=i,f=HT[i].parent;f!=0;c=f,f=HT[f].parent)
		{
			if(HT[f].lchild==c)
				cd[--pos]='0';
			else
				cd[--pos]='1';
		}
		HC[i]=(char *)malloc((n-pos)*sizeof(char));
		strcpy(HC[i],&cd[pos]);
	}//从叶子到根逆向求出每个字符的哈夫曼编码 
	*/
}

int main()
{
	int size,cnt[105];
	cin>>size;
	for(int i=0;i<size;i++)
		cin>>cnt[i];
	sort(cnt,cnt+size);
	HuffmanTree HT;//哈夫曼树 
	HuffmanCode HC;//哈夫曼编码表 
	HuffmanCoding(HT,HC,cnt,size);//进行哈夫曼编码操作 
	int ans=0;
	for(int i=size+1;i<=2*size-1;i++)
		ans+=HT[i].weight;
	cout<<ans<<endl;
	return 0;
}
