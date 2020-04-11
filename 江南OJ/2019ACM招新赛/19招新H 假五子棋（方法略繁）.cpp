#include <bits/stdc++.h>
using namespace std;
int board[15][15]={0};
int main()
{
	int n,m,p,x,y,i,j,a,b,found,jo=1,flag=0;
	cin>>n>>m>>p;
	while(p--)
	{
		cin>>x>>y;
		board[x][y]=2-jo%2;
		jo++;
	}//在棋盘上放置棋子，1代表黑棋，2代表白棋 
	for(a=1;a<=n;a++)
	for(b=1;b<=m;b++)//遍历整个棋盘 
	{
		found=0;
		if(board[a][b]) found=1;
		if(found)
			for(i=a+1;i<=a+4;i++)
			{
				if(board[i][b]!=board[i-1][b]) break;
				else found++;
				if(found==5) {flag=board[a][b];goto label;}
			}//纵向查找 
		found=0;
		if(board[a][b]) found=1;
		if(found)
			for(j=b+1;j<=b+4;j++)
			{
				if(board[a][j]!=board[a][j-1]) break;
				else found++;
				if(found==5) {flag=board[a][b];goto label;}
			}//横向查找 
	}
	label:
	if(flag==0) cout<<"no winner";
	if(flag==1) cout<<"black";
	if(flag==2) cout<<"white";
	return 0;
}
