#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
int n,m,k,q,a,t[1005],ans[1005];
struct node
{
	int poptime,endtime;//第一个人出队时间，最后一个人结束时间 
	queue<int> que;//队伍 
}w[25];//窗口 
int main()
{
	int index=0;//当前处理的客户编号 
	cin>>n>>m>>k>>q;
	for(int i=0;i<k;i++)
		cin>>t[i];
	for(int i=0;i<n;i++)
		w[i].poptime=w[i].endtime=0;//初始化时间 
	for(int i=0;i<min(n*m,k);i++)
	{
		w[index%n].que.push(index);
		w[index%n].endtime+=t[index];
		if(index<n)
			w[index].poptime=t[index];
		ans[index]=w[index%n].endtime;
		index++;
	}
	for(;index<k;index++)
	{
		int temp=0,mint=1999999999;
		for(int i=0;i<n;i++)
		{
			if(w[i].poptime<mint)
			{
				mint=w[i].poptime;
				temp=i;
			}
		}//找到最快空出位置的窗口排队，如果同时空出则默认在前的窗口优先 
		w[temp].que.pop();
		w[temp].que.push(index);
		w[temp].poptime+=t[w[temp].que.front()];
		w[temp].endtime+=t[index];
		ans[index]=w[temp].endtime;
	}
	for(int i=0;i<q;i++)
	{
		cin>>a;
		a--;//下标从0开始 
		if(ans[a]-t[a]<540)
			printf("%02d:%02d\n",ans[a]/60+8,ans[a]%60);//注意时间加上8点 
		else
			printf("Sorry\n");
	}
	return 0;
}
