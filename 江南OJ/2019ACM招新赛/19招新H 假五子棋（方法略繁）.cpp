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
	}//�������Ϸ������ӣ�1������壬2������� 
	for(a=1;a<=n;a++)
	for(b=1;b<=m;b++)//������������ 
	{
		found=0;
		if(board[a][b]) found=1;
		if(found)
			for(i=a+1;i<=a+4;i++)
			{
				if(board[i][b]!=board[i-1][b]) break;
				else found++;
				if(found==5) {flag=board[a][b];goto label;}
			}//������� 
		found=0;
		if(board[a][b]) found=1;
		if(found)
			for(j=b+1;j<=b+4;j++)
			{
				if(board[a][j]!=board[a][j-1]) break;
				else found++;
				if(found==5) {flag=board[a][b];goto label;}
			}//������� 
	}
	label:
	if(flag==0) cout<<"no winner";
	if(flag==1) cout<<"black";
	if(flag==2) cout<<"white";
	return 0;
}
