#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
int n,flag=1,a[100005],k[100005],vis[100005];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	int greedy=1;
	scanf("%d",&k[1]);
	for(int i=2;i<=n;i++)//�ж��Ƿ����̰��������k���������� 
	{
		scanf("%d",&k[i]);
		if(k[i]<k[i-1])
			greedy=0;
	}
	if(greedy)//����̰��������������2��30�֣� 
	{
		//��ǰ����ÿ��λ���ܹ�������Զ�ĵط� 
		int to[100005];
		for(int pos=1;pos<n;pos++)
		{
			int maxpos=0;
			for(int i=1;i<=min(n-pos,k[pos]);i++)
			{
				int newpos=pos+i-a[pos+i];
				if(newpos>maxpos)
					maxpos=newpos;//��������ǰ�� 
			}
			to[pos]=maxpos;
		}
		//for(int i=1;i<n;i++)
		//	printf("%d ",to[i]);
		int pos=1,time=0;
		vis[1]=1;
		while(1)
		{
			if(pos==n)
			{
				flag=0;
				printf("%d\n",time);
				break;
			}
			int newpos=to[pos];
			if(!vis[newpos]&&newpos>pos)
			{
				vis[newpos]=1;
				pos=newpos;
				time++;
			}
			else
				break;
		}
		if(flag)
			printf("-1\n");
		//ֱ��ģ��ᳬʱ 
		/*
		int pos=1,time=0;
		vis[1]=1;
		while(1)
		{
			if(pos==n)
			{
				flag=0;
				printf("%d\n",time);
				break;
			}
			int maxpos=0;
			for(int i=1;i<=min(n-pos,k[pos]);i++)
			{
				if(!vis[pos+i-a[pos+i]]&&pos+i-a[pos+i]>maxpos)
				{
					int newpos=pos+i-a[pos+i];
					vis[newpos]=1;
					if(newpos>maxpos)
						maxpos=newpos;//��������ǰ�� 
				}
			}
			if(maxpos<pos) break;//�޽� 
			pos=maxpos;
			time++;
		}
		if(flag)
			printf("-1\n");
		*/
	}
	else//������1��30�֣���BFS
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
