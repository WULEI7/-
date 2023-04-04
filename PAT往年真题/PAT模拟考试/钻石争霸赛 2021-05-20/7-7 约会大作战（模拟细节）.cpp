#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
int n,m,q,x,y,a[105][105],b[105][105],lasta[105],lastb[105],maxna[105],maxnb[105],cnta[105],cntb[105],total=0;
map<pair<int,int>,int> cnt;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
		cin>>a[i][j];
	for(int i=1;i<=m;i++)
	for(int j=1;j<=n;j++)
		cin>>b[i][j];
	while(q--)//q次询问 
	{
		cin>>x>>y;
		cnt[{x,y}]++;
		//if(cnt[{x,y}]>1) while(1);
		//以上测试说明没通过的样例1和4都存在“如果同一对人被询问两次，会被当成两对人处理。”的情况 
		//if(cnt[{x,y}]==1)
		//加上通过样例0，1，3；不加上通过样例0，2，3 
		{
			if(cnta[x]>=0)
				cnta[x]++;
			if(cntb[y]>=0)
				cntb[y]++;
		}
		if(cnta[x]<=2||cntb[y]<=2)//前两次被询问不配对 
		{
			maxna[x]=max(lasta[x],a[x][y]);//更新好感度阈值 
			maxnb[y]=max(lastb[y],b[y][x]);
			lasta[x]=a[x][y];
			lastb[y]=b[y][x];
			continue;
		}
		else//从第三次询问开始，如果询问的人的好感度大于这个人之前的两个（文字游戏）没能牵手的人，则接受，否则拒绝 
		{
			if(cnta[x]==-1||cntb[y]==-1)//任意一方已经配对成功，不配对 
			{
				//while(1);
				//说明没通过的样例1和4没有经过这个分支 
				/*
				maxna[x]=max(lasta[x],a[x][y]);//更新好感度阈值 
				maxnb[y]=max(lastb[y],b[y][x]);
				lasta[x]=a[x][y];
				lastb[y]=b[y][x];
				*/
				continue;
			}
			else if(a[x][y]>maxna[x]&&b[y][x]>maxnb[y])//符合好感要求，配对成功 
			{
				//cout<<"配对成功";
				cout<<x<<" "<<y<<endl;
				total++;
				cnta[x]=-1;
				cntb[y]=-1;
			}
			/* 
			else//注意if-else分支细节，不能漏考虑情况！ 
			{
				maxna[x]=max(lasta[x],a[x][y]);//更新好感度阈值 
				maxnb[y]=max(lastb[y],b[y][x]);
				lasta[x]=a[x][y];
				lastb[y]=b[y][x];
			}
			*/
			maxna[x]=max(lasta[x],a[x][y]);//更新好感度阈值 
			maxnb[y]=max(lastb[y],b[y][x]);
			lasta[x]=a[x][y];
			lastb[y]=b[y][x];
		}
	}
	if(total==0)
		cout<<"PTA is my only love"<<endl;
	return 0;
}
