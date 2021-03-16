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
}HTNode,*HuffmanTree;//��̬��������洢�������� 
typedef char** HuffmanCode;//��̬��������洢����������� 

void Select(HuffmanTree &HT,int num,int &child1,int &child2)//ע��Select������д�� 
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
	//���ϲ�����ȷ��Selectд����Ŀ����ʹ����Ĺ�������������ͬ�Ľṹ 
	//֮ǰ�����ݽṹ��ҵ��ʱ��д�����£���С�������ݿ��ܻ���������ű�OJ��ֻ���õ�90�� 
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
}//��HT[1]-HT[num]��ѡ��parentΪ0��weight��С��������㣬����ŷֱ�Ϊs1��s2 

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
	}//���������� 
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
	}//��Ҷ�ӵ����������ÿ���ַ��Ĺ��������� 
	*/
}

int main()
{
	int size,cnt[105];
	cin>>size;
	for(int i=0;i<size;i++)
		cin>>cnt[i];
	sort(cnt,cnt+size);
	HuffmanTree HT;//�������� 
	HuffmanCode HC;//����������� 
	HuffmanCoding(HT,HC,cnt,size);//���й������������ 
	int ans=0;
	for(int i=size+1;i<=2*size-1;i++)
		ans+=HT[i].weight;
	cout<<ans<<endl;
	return 0;
}
