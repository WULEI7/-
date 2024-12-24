#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
const int MAXN = 100005;
int n,flag=1,a[100005],k[100005],vis[100005];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	int greedy=1;
	scanf("%d",&k[1]);
	for(int i=2;i<=n;i++)//判断是否符合贪心条件（k单调不降） 
	{
		scanf("%d",&k[i]);
		if(k[i]<k[i-1])
			greedy=0;
	}
	if(greedy)//符合贪心条件，子任务2（30分） 
	{
		int dp[MAXN];
	    for (int i = 1; i <= n; i++) {
	        dp[i] = MAXN;
	    }
	    dp[n] = 0; // 到达终点的跳跃次数为0
	    for (int i = n; i >= 1; i--) {
	        int nextPos = i + k[i] - a[i + k[i]];
	        if (nextPos <= n) {
	            dp[i] = min(dp[i], dp[nextPos] + 1);
	        }
	    }
	    if (dp[1] == MAXN) {
	        printf("-1\n"); // 如果起点无法到达终点，输出-1
	    } else {
	        printf("%d\n", dp[1]); // 否则输出从起点到终点的最少跳跃次数
	    }
	}
	else//子任务1（30分）：BFS
	{
		queue<pair<int,int> > q;
		q.push({1,0});
		vis[1]=1;
		while(!q.empty())
		{
			int pos=q.front().first;
			int time=q.front().second;
			q.pop();
			if(pos==n)
			{
				flag=0;
				printf("%d\n",time);
				break;
			}
			for(int i=1;i<=k[pos];i++)
			{
				if(pos+i<=n&&!vis[pos+i-a[pos+i]])
				{
					//cout<<pos+i-a[pos+i]<<endl;
					vis[pos+i-a[pos+i]]=1;
					q.push({pos+i-a[pos+i],time+1});
				}
			}
		}
		if(flag)
			printf("-1\n");
	}
	return 0;
}
