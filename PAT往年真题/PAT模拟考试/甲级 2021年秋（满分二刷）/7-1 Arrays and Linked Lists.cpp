#include <iostream>
#include <cstdio>
using namespace std;
int n,k,q,sta,len,temp=0,total=0,ans=0;
int used[10005];
struct node
{
	int add,num;
}p[10000005];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)//n������ 
	{
		cin>>sta>>len;
		temp=total;
		for(int j=temp;j<temp+len;j++)
		{
			p[j].add=sta+4*(j-temp);
			p[j].num=i;
		}
		total+=len;
	}
	for(int i=1;i<=k;i++)//k�β�ѯ 
	{
		cin>>q;
		if(q>=total)
		{
			cout<<"Illegal Access"<<endl;
			continue;
		}
		used[p[q].num]=1;
		cout<<p[q].add<<endl;
	}
	used[1]=1;//Ĭ�ϵ�һ�����鱻���ʹ� 
	for(int i=1;i<=n;i++)//ע���ڲ�ѯλ��֮ǰ�����鶼���뱻���ʹ��� 
		if(used[i]==1)
			ans=i;
	cout<<ans<<endl;
	return 0;
}
