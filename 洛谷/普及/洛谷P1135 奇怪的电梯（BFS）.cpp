#include <iostream>
#include <cstdio> 
#include <queue>
using namespace std;
int n,x,y,s[205],vis[205];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>x>>y;
	for(int i=1;i<=n;i++)
		cin>>s[i];
	queue<pair<int,int>> q;//BFS�Ķ��� 
	q.push({x,0});
	vis[x]=1;//������ʼ�� 
	while(!q.empty())
	{
		int temp=q.front().first,time=q.front().second;
		q.pop();
		if(temp==y)//����Ŀ�Ĳ㣬�����С���� 
		{
			cout<<time<<endl;
			return 0;
		}
		if(temp-s[temp]>=1&&!vis[temp-s[temp]])//���ܵ�С��1�� 
		{
			q.push({temp-s[temp],time+1});
			vis[temp-s[temp]]=1;
		}
		if(temp+s[temp]<=n&&!vis[temp+s[temp]])//���ܵ�����n�� 
		{
			q.push({temp+s[temp],time+1});
			vis[temp+s[temp]]=1;
		}
	}
	cout<<-1<<endl;//���ܵ��������-1 
	return 0;
}
