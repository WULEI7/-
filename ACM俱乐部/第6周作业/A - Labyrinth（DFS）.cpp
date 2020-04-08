#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
char L[1002][1002];
int rec[1002][1002]={0};//标记是否访问过 
int ans=0,xx,yy,t,r,c,x,y;
void dfs(int a,int b,int temp)
{
	if(temp>ans)
	{
		ans=temp;
		xx=a;yy=b;
	}
	rec[a][b]=1;
	if(a-1>=0&&L[a-1][b]=='.'&&rec[a-1][b]==0)
	{
		rec[a-1][b]=1;
		dfs(a-1,b,temp+1);
	}
	if(a+1<r&&L[a+1][b]=='.'&&rec[a+1][b]==0)
	{
		rec[a+1][b]=1;
		dfs(a+1,b,temp+1);
	}
	if(b-1>=0&&L[a][b-1]=='.'&&rec[a][b-1]==0)
	{
		rec[a][b-1]=1;
		dfs(a,b-1,temp+1);
	}
	if(b+1<c&&L[a][b+1]=='.'&&rec[a][b+1]==0)
	{
		rec[a][b+1]=1;
		dfs(a,b+1,temp+1);
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>c>>r;
		for(int i=0;i<r;i++)
			for(int j=0;j<c;j++)
				cin>>L[i][j];
		for(int i=0;i<r;i++)
			for(int j=0;j<c;j++)
				if(L[i][j]=='.')
				{x=i;y=j;break;}
		ans=0;//注意初始化 
		dfs(x,y,0);
		memset(rec,0,sizeof(rec));
		dfs(xx,yy,0);
		memset(rec,0,sizeof(rec));
		cout<<"Maximum rope length is "<<ans<<"."<<endl;
	}
	return 0;
}
