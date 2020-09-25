#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
const int maxn=200005;
using namespace std;
int vec[26][maxn]={0};
int p[maxn];
int find(int x)
{
	return p[x]==x ? x:p[x]=find(p[x]);
}//���鼯 
void unity(int x,int y)
{
	int s=find(x);
	int t=find(y);
	p[s]=t;
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,ans=0;
	string s;
	cin>>n;
	for(int i=1;i<=n;i++)
		p[i]=i;//���鼯��ʼ�� 
	for(int i=1;i<=n;i++)
	{
		cin>>s;
		int len=s.length();
		for(int j=0;j<len;j++)
				vec[s[j]-'a'][i]=1;
	}//��1��n�ֱ��ʾ�ַ����ı�� 
	for(int i=0;i<26;i++)
	{
		int x,y,pos=-1;
		for(int j=1;j<=n;j++)
		{
			if(vec[i][j]==1)
			{
				pos=j;
				x=find(j);//�����ں���û�м�ʱ���£�Ҫע��ϸ�� 
				break;
			}
		}
		if(pos==-1) continue;
		for(int j=pos+1;j<=n;j++)
		{
			if(vec[i][j]==1)
			{
				y=find(j);
				unity(x,y);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(i==find(i))
			ans++;
	}
	cout<<ans<<endl;
	return 0;
}
