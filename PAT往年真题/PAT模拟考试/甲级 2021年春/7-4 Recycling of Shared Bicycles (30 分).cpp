#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int INF=1000000000;
int n,m,G[205][205],vis[205],ans=0;
vector<int> vec;//�洢����·�� 
void dfs(int pos,int temp)
{
	if(vec.size()==n)//1-n���ѷ��ʹ� 
	{
		ans=temp;
		return;
	}
	int minpos=0,mindis=INF,flag=0;
	for(int i=0;i<=n;i++)
	{
		if(!vis[i])
			if(G[pos][i]<mindis)
			{
				flag=1;
				mindis=G[pos][i];
				minpos=i;
			}
	}//�ҵ���̾���ĵ㣨������ͬʱ���С�ĵ����ȣ� 
	if(!flag) return;//û�е���Է��� 
	vis[minpos]=1;
	vec.emplace_back(minpos);
	dfs(minpos,temp+mindis);//������һ���� 
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	int a,b,c;
	for(int i=0;i<=n;i++)
	for(int j=0;j<=n;j++)
	{
		if(i==j)
			G[i][j]=0;
		else
			G[i][j]=INF;
	}//�ڽӾ����ʼ�� 
	for(int i=0;i<m;i++)
	{
		cin>>a>>b>>c;
		G[a][b]=G[b][a]=c;
	}//����ͼ 
	for(int i=0;i<=n;i++)
	for(int j=0;j<=n;j++)
	for(int k=0;k<=n;k++)
		if(G[i][k]+G[k][j]<G[i][j])
			G[i][j]=G[i][k]+G[k][j];//Floyd���·���� 
	vis[0]=1;
	dfs(0,0);//��0�������ʼ���� 
	cout<<"0";
	for(int i=0;i<vec.size();i++)
		cout<<" "<<vec[i];
	cout<<endl;//���·�� 
	if(vec.size()==n)
		cout<<ans<<endl;//������е㶼���ʹ������·������֮�� 
	else
	{
		int flag=1;
		for(int i=0;i<=n;i++)
			if(!vis[i])
			{
				if(flag)
				{
					cout<<i;
					flag=0;
				}
				else
					cout<<" "<<i;
			}
	}//���δ���ʵ��ĵ� 
	return 0;
}
