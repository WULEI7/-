#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
int num[105][2],xue[105][8];
int main()
{
	int t;
	cin>>t;
	for(int T=1;T<=t;T++)
	{
		printf("Case %d:\n",T);
		memset(num,0,sizeof(num));
		memset(xue,0,sizeof(xue));
		queue<int> q;
		int m,n,k,x,sum=0;//学生总数sum 
		cin>>m;
		for(int i=1;i<=m;i++)
		{
			cin>>n>>k;
			num[i][0]=n;//宿舍编号 
			num[i][1]=7-k;//宿舍空余人数 
			sum+=k;//总人数 
			for(int j=1;j<=k;j++)
			{
				cin>>xue[i][j];
			}
		}
		int tot;//需要的宿舍数量 
		if(sum%7)
			tot=sum/7+1;
		else
			tot=sum/7;
		for(int i=1;i<=tot;i++)
		{
			if(num[i][1]>0)
				q.push(i);
		}
		int pos=tot+1,temp=1;//当前对宿舍pos的学生进行调换，当前学生是当前宿舍的第temp个 
		while(pos<=m)
		{
			if(xue[pos][temp]>0)
			{
				printf("%d %d\n",xue[pos][temp],num[q.front()][0]);
				temp++;
				num[q.front()][1]--;
			}
			else
			{
				pos++;
				temp=1;
			}
			if(num[q.front()][1]==0)
				q.pop();
		}
	}
	return 0;
}
