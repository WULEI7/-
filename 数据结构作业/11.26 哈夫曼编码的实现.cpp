#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
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

void Select(HuffmanTree &HT,int num,int &child1,int &child2)
{
	child1=0;child2=0;
	int w1,w2;
	for(int i=1;i<=num;i++)
	{
		if(HT[i].parent==0)
		{
			if(child1==0||w1>w2&&w1>HT[i].weight)
			{
				child1=i;
				w1=HT[i].weight;
				continue;
			}
			if(child2==0||w2>w1&&w2>HT[i].weight)
			{
				child2=i;
				w2=HT[i].weight;
				continue;
			}
		}
	}
}//��HT[1]-HT[num]��ѡ��parentΪ0��weight��С��������㣬����ŷֱ�Ϊs1��s2 

void HuffmanCoding(HuffmanTree &HT,HuffmanCode &HC,int *w,int n)
{
	int child1,child2;
	if(n<=1) return;
	int m=n*2-1;
	HT=(HuffmanTree)malloc((m+1)*sizeof(HTNode));
	for(int i=1;i<=n;i++,w++)
		HT[i]={*w,0,0,0};
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
}


int main()
{
	string s;
	int len;
	cout<<"�������ַ�����"<<endl;
	getline(cin,s);
	len=s.length();
	map<char,int> mp;//����ͳ���ַ����е��ַ�������ִ��� 
	map<char,char *> MP;//���ڴ�ȡ���ַ���Ӧ�Ĺ��������� 
	for(int i=0;i<len;i++)
		mp[s[i]]++;
	int size=mp.size();
	char *ch=(char *)malloc((size)*sizeof(char));
	int *cnt=(int *)malloc((size)*sizeof(int));
	int i;
	map<char,int>::iterator it;//map������ 
	for(it=mp.begin(),i=0;it!=mp.end();it++,i++)
		cnt[i]=it->second;
	HuffmanTree HT;//�������� 
	HuffmanCode HC;//����������� 
	HuffmanCoding(HT,HC,cnt,size);//���й������������ 
	for(it=mp.begin(),i=0;it!=mp.end();it++,i++)
	{ 
		ch[i]=it->first;
		MP[ch[i]]=HC[i+1];
	}
	cout<<"���ַ���Ӧ�Ĺ���������Ϊ��"<<endl;
	for(i=1;i<=size;i++)
		cout<<ch[i-1]<<" "<<HC[i]<<endl;
	cout<<"ԭ�ַ�����Ӧ�Ĺ���������Ϊ��"<<endl;
	for(i=0;i<len;i++)
		cout<<MP[s[i]];
	cout<<endl<<endl;
	
	//���沿��ʵ��������̣��������뵱ǰ�����Ѵ����ַ��ı��룩 
	cout<<"��������������룺"<<endl;
	cin>>s;
	len=s.length();
	string t;
	int temp=2*size-1;
	for(i=0;i<len;i++)
	{
		if(s[i]=='0')
		{
			if(HT[temp].lchild!=0)
				temp=HT[temp].lchild;
			if(HT[temp].lchild==0&&HT[temp].rchild==0)
			{
				t+=ch[temp-1];
				temp=2*size-1;
			}
		}
		if(s[i]=='1')
		{
			if(HT[temp].rchild!=0)
				temp=HT[temp].rchild;
			if(HT[temp].lchild==0&&HT[temp].rchild==0)
			{
				t+=ch[temp-1];
				temp=2*size-1;
			}
		}
	}
	cout<<"�����������Ӧ��ԭ�ַ���Ϊ��"<<endl;
	cout<<t<<endl;
	
	return 0;
}
