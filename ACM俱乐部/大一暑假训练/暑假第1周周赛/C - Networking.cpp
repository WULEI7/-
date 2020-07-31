#include <iostream>
#include <cstring>
#define inf 99999999
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int p,r,vis[105],dis[105],map[105][105];
	while(cin>>p)
	{
		if(p==0) break;
		cin>>r;
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
		for(int i=1;i<=p;i++)
		{
			int minn=inf,k=0;
			for(int j=1;j<=p;j++)
				if(vis[j]==0&&dis[j]<minn)
				{
					minn=dis[j];
					k=j;
				}
			vis[k]=1;
			for(int j=1;j<=p;j++)
				if(vis[j]==0&&dis[j]>map[k][j])
					dis[j]=map[k][j];
		}
		int ans=0;
		for(int i=1;i<=p;i++)
			ans+=dis[i];
		cout<<ans<<endl;
	}//最小生成树，Prim算法 
	return 0;
}
