#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int num=20005;
int vis[num],fanode[num],faedge[num];//点的祖先节点，边的祖先节点 
int havenode[num],haveedge[num];//祖先节点连接点数，祖先节点连接边数 
int find(int x)
{
	return x==fanode[x]?x:fanode[x]=find(fanode[x]);
}
int main()
{
	int T;
	cin>>T;
	for(int t=1;t<=T;t++)
	{
		int n,m,a,b,ans=0,fix=0;
		cin>>n>>m;
		for(int i=1;i<=n;i++)
		{
			fanode[i]=i;
			vis[i]=havenode[i]=haveedge[i]=0;
		}
		for(int i=1;i<=m;i++)
		{
			cin>>a>>b;
			vis[a]=vis[b]=1;
			int x=find(a),y=find(b);
			if(x!=y)
				fanode[x]=fanode[y];
			faedge[i]=fanode[y];
		}
		for(int i=1;i<=n;i++)
			havenode[find(fanode[i])]++;
		for(int i=1;i<=m;i++)
			haveedge[find(faedge[i])]++;
		//for(int i=1;i<=n;i++)
		//	cout<<havenode[i]<<" "<<haveedge[i]<<endl;
		for(int i=1;i<=n;i++)
		{
			if(vis[i]&&havenode[i])
			{
				ans++;//至少有两个结点的连通分量 
				if(havenode[i]<=haveedge[i])
					fix++;//存在环的连通分量 
			}
		}
		printf("Night sky #%d: %d constellations, of which %d need to be fixed.\n\n",t,ans,fix);
	}
	return 0;
}
