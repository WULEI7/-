#include <bits/stdc++.h>
using namespace std;
//����ͼƥ�䣺�������㷨 
//int G[110][110];
vector<int> G[100010];
int cant[100010];
int match[100010],reserve[100010];
int k,t,m,n;

bool dfs(int x)
{
	int size=G[x].size();
	memset(cant,0,sizeof(cant));
	for(int i=0;i<size;i++)
		cant[G[x][i]]=1;
	for(int i=1;i<=n;i++)
	{
		if(i==x) continue;
		if(cant[i]) continue;
		if(!reserve[i])
		{	
			reserve[i]=1;
			if(!match[i]||dfs(match[i]))
			{
				match[i]=x;
				return true;
			}
		}
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>k;
	m=n;
	for(int i=0;i<k;i++)
	{
		int a,b;
		cin>>a>>b;
		//G[a][b]=1;
		//G[b][a]=1;
		//�����������ǲ���ƥ��ģ�����ģ���ǿ���ƥ��� 
		G[a].push_back(b);
		G[b].push_back(a);
	}
	int sum=0;
	for(int i=1;i<=m;i++)
	{
		memset(reserve,0,sizeof(reserve));
		if(dfs(i)) sum++;
	}
	cout<<sum/2<<endl;
	return 0;
}
