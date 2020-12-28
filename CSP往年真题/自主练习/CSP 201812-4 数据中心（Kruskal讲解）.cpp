#include <cstdio>
#include <iostream>
#include <algorithm>
const int maxn=100005;
using namespace std;
int u[maxn],v[maxn],w[maxn],p[maxn],r[maxn];
//u v w����ֱ��ʾ�ߵ���� �յ��Ȩֵ
//p�����ʾ���ĸ���� r�����ʾ�ߵı�� 
int cmp(const int i,const int j)
{
	return w[i]<w[j];
}//��Ȩֵ�Ƚ� 
int find(int x)
{
	return p[x]==x ? x:p[x]=find(p[x]);
}//���鼯���� 
int main()
{
	int n,m,root,ans=0;
	cin>>n>>m>>root;
	for(int i=1;i<=n;i++)
		p[i]=i;//������ʼ�� 
	for(int i=0;i<m;i++)
		r[i]=i;//�ߵı�� 
	for(int i=0;i<m;i++)
		cin>>u[i]>>v[i]>>w[i];//�������� 
	sort(r,r+m,cmp);//�ߵ����� 
	for(int i=0;i<m;i++)
	{
		int e=r[i];
		int x=find(u[e]);
		int y=find(v[e]);
		if(x!=y)//�����յ㲻��ͬһ������ 
		{
			p[x]=y;
			if(w[e]>ans)
				ans=w[e];
		}//����ans��ֵ 
	}
	cout<<ans<<endl;//������ 
	return 0;
}
