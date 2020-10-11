#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
const int inf=2147483647;//int��Χ���ֵ��������һ�����Ե���ڲ��ܴﵽ����� 
using namespace std;
struct node
{
	int v;
	int d;
};//���յ�ͳ��� 
vector<vector<node> > map(100005);//ͼ 
typedef pair<int,int> par;//���Ⱥͱ��յ� 
priority_queue<par,vector<par>,greater<par> > q;//С���� 
int vis[100005],n,m,s;
int dis[100005];
void Dijkstra(int x)//���Ϊx 
{
	dis[x]=0;//�˾�ز����� 
	q.push(par(0,x));
	while(!q.empty())
	{
		par k=q.top();
		q.pop();
		int u=k.second;
		if(vis[u]) continue;
		int size=map[u].size();
		for(int i=0;i<size;i++)
		{
			node t=map[u][i];
			if(dis[t.v]>dis[u]+t.d)
			{
				dis[t.v]=dis[u]+t.d;
				q.push(par(dis[t.v],t.v));
			}
		}//���������· 
	}
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>s;
	for(int i=0;i<=n;i++)
	{
		vis[i]=0;
		dis[i]=inf;
	}//ע���ʼ�� 
	while(m--)
	{
		node n1,n2;
		int a,b,c;
		cin>>a>>b>>c;
		/*n1.d=n2.d=c;
		n1.v=b,n2.v=a;
		map[a].push_back(n1);
		map[b].push_back(n2);*/
		//ע�����������ͼ��
		n1.d=c;
		n1.v=b;
		map[a].push_back(n1); 
	}
	Dijkstra(s);//�����s����� 
	printf("%d",dis[1]);
	for(int i=2;i<=n;i++)
		printf(" %d",dis[i]);
	printf("\n");
	return 0;
}
