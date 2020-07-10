#include <iostream>
#include <cstring>
#define inf 99999999
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,vis[105],dis[105],map[105][105];
	while(cin>>n)
	{
		memset(vis,0,sizeof(vis));
		memset(dis,0,sizeof(dis));
		memset(map,0,sizeof(map));//此题输入完整的邻接矩阵，注意一般的初始化 
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				cin>>map[i][j];
		for(int i=1;i<=n;i++)
			dis[i]=map[1][i];
		for(int i=1;i<=n;i++)
		{
			int minn=inf,k=0;
			for(int j=1;j<=n;j++)
				if(vis[j]==0&&dis[j]<minn)
				{
					minn=dis[j];
					k=j;
				}
			vis[k]=1;
			for(int j=1;j<=n;j++)
				if(vis[j]==0&&dis[j]>map[k][j])
					dis[j]=map[k][j];
		}
		int ans=0;
		for(int i=1;i<=n;i++)
			ans+=dis[i];
		cout<<ans<<endl;
	}//最小生成树，Prim算法 
	return 0;
}
