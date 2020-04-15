#include <iostream>
#include <queue>
#include <cstring> 
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,x,y,s[205],vis[205];
	while(cin>>n)
	{
		if(n==0) break;
		cin>>x>>y;
		for(int i=1;i<=n;i++)
			cin>>s[i];
		queue <int> q;
		q.push(x);
		memset(vis,0,sizeof(vis));//ע���ʼ�� 
		vis[x]=1;//����Ĭ����ʼ���Ŀ�Ĳ㲻��ͬһ�� 
		while(!q.empty())
		{
			int temp=q.front();
			q.pop();
			if(temp-s[temp]>=1&&!vis[temp-s[temp]])//���ܵ�С��1�� 
			{
				q.push(temp-s[temp]);
				vis[temp-s[temp]]=vis[temp]+1;
			}
			if(temp+s[temp]<=n&&!vis[temp+s[temp]])//���ܵ�����n�� 
			{
				q.push(temp+s[temp]);
				vis[temp+s[temp]]=vis[temp]+1;
			}
		}
		cout<<vis[y]-1<<endl;//�������Ŀ�Ĳ㣬��������ٵĲ��������ܵ��������-1 
	}
	return 0;
}
