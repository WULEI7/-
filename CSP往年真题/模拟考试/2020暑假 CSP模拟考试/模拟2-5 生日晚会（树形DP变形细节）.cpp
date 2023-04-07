#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=6005;
int n,m,a,b,fat[maxn],vis[maxn],dp[maxn][2];
void treedp(int node)
{
	vis[node]=1;
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==0&&fat[i]==node)
		{
			treedp(i);
			if(node==m)//m������ȥ��ע������λ�� 
				dp[node][0]=0;
			else
				dp[node][0]+=max(dp[i][0],dp[i][1]);
			dp[node][1]+=dp[i][0];
		}
	}
}//����DP��ע����Σ���ΪС�Ʊ���ȥ 
int main()
{
	scanf("%d%d",&n,&m);
	memset(fat,0,sizeof(fat));
	memset(vis,0,sizeof(vis));
	memset(dp,0,sizeof(dp));
	int root=1;//��ǰ��дΪ0�����������е��˷�ʱ�� 
	for(int i=1;i<=n;i++)
		scanf("%d",&dp[i][1]);
	for(int i=1;i<=n-1;i++)
	{
		scanf("%d%d",&a,&b);
		fat[a]=b;
		//if(root==a) root=b;
	}
	//while(fat[root])
	//	root=fat[root];//�ҵ������˾ 
	for(int i=1;i<=n;i++)
		if(fat[i]==0)
		{root=i;break;}//����дҲ���� 
	treedp(root);
	printf("%d\n",max(dp[root][0],dp[root][1]));
	return 0;
}
