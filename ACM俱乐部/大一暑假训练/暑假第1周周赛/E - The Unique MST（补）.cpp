#include <iostream>
#include <cstring>
#define inf 99999999
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t,p,r,vis[105],dis[105],map[105][105];
	cin>>t;
	while(t--)
	{
		int ans=0,flag=1;
		cin>>p>>r;
		memset(vis,0,sizeof(vis));
		memset(dis,0,sizeof(dis));
		for(int i=1;i<=p;i++)
			for(int j=1;j<=p;j++)
				if(i==j) map[i][j]=0;
				else map[i][j]=inf;//图的初始化 
		for(int i=1;i<=r;i++)
		{
			int a,b,c;
			cin>>a>>b>>c;
			if(map[a][b]>c)
				map[a][b]=map[b][a]=c;
		}
		for(int i=1;i<=p;i++)
			dis[i]=map[1][i];
		vis[1]=1;//从1点开始访问 
		for(int i=1;i<=p;i++)
		{
			int minn=inf,k=0;
			for(int j=1;j<=p;j++)
				if(vis[j]==0&&dis[j]<minn)
				{
					minn=dis[j];
					k=j;
				}
			//ans+=minn;也可以在这里计算ans 
			int check=0;
			for(int j=1;j<=p;j++)
				if(vis[j]&&map[k][j]==minn)
					check++;
			if(check>1) flag=0;//检查最小生成树是否唯一 
			vis[k]=1;//必须放在检查的后面，否则就错误 
			for(int j=1;j<=p;j++)
				if(vis[j]==0&&dis[j]>map[k][j])
					dis[j]=map[k][j];
			if(flag==0) break;
		}
		for(int i=1;i<=p;i++)
			ans+=dis[i];//也可以在上面计算ans 
		if(flag)
			cout<<ans<<endl;
		else
			cout<<"Not Unique!"<<endl;
	}
	return 0;
}
