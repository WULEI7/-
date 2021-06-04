#include <iostream>
#include <cstdio>
#include <queue>
#include <stack>
using namespace std;
const int INF=0x3f3f3f3f;//����� 
int n,g[105][105],dis[105],pre[105],vis[105];
struct edge
{
	int u,v,d;//�ߵ���㡢�յ㡢Ȩֵ 
	bool operator < (const edge &a) const
	{
		return d>a.d;
	}
};
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	{
		cin>>g[i][j];
		if(g[i][j]==0)
			g[i][j]=INF;
	}
	priority_queue<edge> q;//���ȶ��� 
	int temp=1,cnt=0;//��ǰ����ͱ��� 
	for(int i=1;i<=n;i++)
	{
		if(i!=temp)
		{
			pre[i]=temp;
			dis[i]=g[temp][i];
			q.push({temp,i,g[temp][i]});
		}
	}//�ӽ��temp��ʼ������Ϊ�ӽ��1��ʼ 
	while(!q.empty())
	{
		edge t=q.top();
		q.pop();
		int v=t.v;
		if(vis[v]) continue;//�Ѿ����Ѽ����ļ��ϵ��� 
		vis[v]=1;
		cnt++;
		if(cnt==n-1) break;
		temp=v;
		for(int i=1;i<=n;i++)
		{
			if(!vis[i]&&dis[temp]+g[temp][i]<dis[i])
			{
				dis[i]=dis[temp]+g[temp][i];
				pre[i]=temp;
				q.push({temp,i,dis[temp]+g[temp][i]});
			}
		}//�������ȶ��� 
	}
	for(int i=2;i<=n;i++)
	{
		if(dis[i]==INF)
		{
			cout<<"inf: 1->"<<i<<endl;
			continue;
		}//���Դ1���ö���û��·���������"inf: 1->u" 
		stack<int> s;
		int t=i;
		while(t!=0)
		{
			s.push(t);
			t=pre[t];
		}
		cout<<dis[i]<<": "<<s.top();
		s.pop();
		while(!s.empty())
		{
			cout<<"->"<<s.top();
			s.pop();
		}
		cout<<endl;
	}//������ 
	return 0;
}
