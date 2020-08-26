#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
int key[1005];
struct node
{
	int num,time,opt;//取出为1，放回为2 
};
bool operator < (node a,node b)//注意优先队列中“<”的比较 
{
	if(a.time!=b.time) return a.time>b.time;
	else if(a.opt!=b.opt) return a.opt<b.opt;
	else return a.num>b.num;
}
priority_queue<node> que;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,k,w,s,c;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		key[i]=i;
	while(k--)
	{
		cin>>w>>s>>c;
		node t;
		t.num=w;t.time=s;t.opt=1;
		que.push(t);
		t.time=s+c;t.opt=2;
		que.push(t);
	}
	while(!que.empty())
	{
		node t=que.top();que.pop();
		if(t.opt==1)//取出 
		{
			for(int i=1;i<=n;i++)
			{
				if(key[i]==t.num)
				{
					key[i]=0;
					break;
				}
			}
		}
		else if(t.opt==2)//放回 
		{
			for(int i=1;i<=n;i++)
			{
				if(key[i]==0)
				{
					key[i]=t.num;
					break;
				}
			}
		}
	}
	printf("%d",key[1]);
	for(int i=2;i<=n;i++)
		printf(" %d",key[i]);
	printf("\n");
	return 0;
}
