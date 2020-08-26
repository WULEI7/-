#include <cstdio>
#include <iostream>
using namespace std;
char map[60][60];
int r,c,sx,sy,tx,ty,vis1[60][60],vis2[60][60];//r行c列，注意后面x是行，y是列 
int check1(int x,int y)
{
	if(x<1||x>r||y<1||y>c||map[x][y]=='#'||vis1[x][y])
		return 0;
	return 1;
}
int check2(int x,int y)
{
	if(x<1||x>r||y<1||y>c||map[x][y]=='#'||vis2[x][y])
		return 0;
	return 1;
}
void dfs1(int x,int y)
{
	vis1[x][y]=1;
	char t=map[x][y];//注意使用局部变量而非全局变量，否则造成错误！ 
	if(check1(x-1,y)&&(t=='S'||t=='T'||t=='+'||t=='|'))
		dfs1(x-1,y);
	if(check1(x+1,y)&&(t=='S'||t=='T'||t=='+'||t=='|'||t=='.'))
		dfs1(x+1,y);
	if(check1(x,y-1)&&(t=='S'||t=='T'||t=='+'||t=='-'))
		dfs1(x,y-1);
	if(check1(x,y+1)&&(t=='S'||t=='T'||t=='+'||t=='-'))
		dfs1(x,y+1);
	return;
}
void dfs2(int x,int y)
{
	char t; 
	vis2[x][y]=1;
	t=map[x-1][y];
	if(check2(x-1,y)&&(t=='S'||t=='T'||t=='+'||t=='|'||t=='.'))
		dfs2(x-1,y);
	t=map[x+1][y];
	if(check2(x+1,y)&&(t=='S'||t=='T'||t=='+'||t=='|'))
		dfs2(x+1,y);
	t=map[x][y-1];
	if(check2(x,y-1)&&(t=='S'||t=='T'||t=='+'||t=='-'))
		dfs2(x,y-1);
	t=map[x][y+1];
	if(check2(x,y+1)&&(t=='S'||t=='T'||t=='+'||t=='-'))
		dfs2(x,y+1);
	return;
}//从终点反向搜索，注意区别 
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>r>>c;
	for(int i=1;i<=r;i++)
	for(int j=1;j<=c;j++)
	{
		cin>>map[i][j];
		if(map[i][j]=='S')
		{sx=i;sy=j;}
		if(map[i][j]=='T')
		{tx=i;ty=j;}
	}
	dfs1(sx,sy);
	dfs2(tx,ty);
	if(vis1[tx][ty])
	{
		int ans=0;
		for(int i=1;i<=r;i++)
		for(int j=1;j<=c;j++)
			if(vis1[i][j]==1&&vis2[i][j]==0)
				ans++;
		printf("%d\n",ans);
	}
	else printf("I'm stuck!\n");
	return 0;
}
