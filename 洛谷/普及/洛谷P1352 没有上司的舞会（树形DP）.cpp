#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=6005;
int n,a,b,fat[maxn],vis[maxn],dp[maxn][2];
void treedp(int node)
{
	vis[node]=1;
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==0&&fat[i]==node)
		{
			treedp(i);
			dp[node][0]+=max(dp[i][0],dp[i][1]);
			dp[node][1]+=dp[i][0];
		}//0表示不来，1表示来 
	}
}//树形DP 
int main()
{
	scanf("%d",&n);
	memset(fat,0,sizeof(fat));
	memset(vis,0,sizeof(vis));
	memset(dp,0,sizeof(dp));
	int root=1;
	for(int i=1;i<=n;i++)
		scanf("%d",&dp[i][1]);
	for(int i=1;i<=n-1;i++)
	{
		scanf("%d%d",&a,&b);
		fat[a]=b;
		//if(root==a) root=b;
	}
	while(fat[root])
		root=fat[root];//找到最高上司 
	treedp(root);
	printf("%d\n",max(dp[root][0],dp[root][1]));
	return 0;
}
