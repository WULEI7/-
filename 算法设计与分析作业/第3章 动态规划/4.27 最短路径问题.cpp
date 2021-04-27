#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;
int r,c,dis[105][105],dir[105][105];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>r>>c;
	for(int i=1;i<=r;i++)
	for(int j=1;j<=c;j++)
		cin>>dis[i][j];
	for(int i=2;i<=r;i++)
	{
		dis[i][1]+=dis[i-1][1];
		dir[i][1]=1;//���������� 
	}
	for(int j=2;j<=c;j++)
	{
		dis[1][j]+=dis[1][j-1];
		dir[1][j]=2;//���������� 
	}
	for(int i=2;i<=r;i++)
	for(int j=2;j<=c;j++)
	{
		if(dis[i][j]+dis[i-1][j]<=dis[i][j]+dis[i][j-1])
		{
			dis[i][j]+=dis[i-1][j];
			dir[i][j]=1; 
		}//���������� 
		else
		{
			dis[i][j]+=dis[i][j-1];
			dir[i][j]=2;
		}//���������� 
	}//��̬�滮 
	stack<pair<int,int> > ans;
	int tr=r,tc=c;
	while(!(tr==1&&tc==1))
	{
		ans.push({tr,tc});
		if(dir[tr][tc]==1)
			tr--;
		else
			tc--;
	}
	ans.push({1,1});
	cout<<dis[r][c]<<endl;//���·������ 
	while(!ans.empty())
	{
		cout<<ans.top().first<<" "<<ans.top().second<<endl;
		ans.pop();
	}//���·�� 
	return 0;
}
