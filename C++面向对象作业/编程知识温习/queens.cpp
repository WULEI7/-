#include <bits/stdc++.h>
using namespace std;
int board[9][9]={0};//棋盘每格初始值赋为0 
int main()
{
	char a[9];
	int n,i,j,row,flag=1;
	for(n=1;n<=8;n++)
	{
		cin>>a[n];//输入
		if(a[n]=='*')
			row=n;//若是*号则记录空行的位置 
 	else
		{
			for(i=1;i<=8;i++)
				board[i][a[n]-'0']=1;
			for(j=1;j<=8;j++)
				board[n][j]=1;
			for(i=n,j=a[n]-'0';i>=1&&i<=8&&j>=1&&j<=8;i--,j--)
				board[i][j]=1;
			for(i=n,j=a[n]-'0';i>=1&&i<=8&&j>=1&&j<=8;i++,j++)
				board[i][j]=1;
			for(i=n,j=a[n]-'0';i>=1&&i<=8&&j>=1&&j<=8;i--,j++)
				board[i][j]=1;
			for(i=n,j=a[n]-'0';i>=1&&i<=8&&j>=1&&j<=8;i++,j--)
				board[i][j]=1;
		}//将棋盘上皇后能攻击到的所有位置赋值为1 
	} 
	for(n=1;n<=8;n++)
		if(board[row][n]==0)
		{
			cout<<n;
			flag=0;
		}//对空行每格进行检查并输出答案，答案只可能是唯一的或者无解 
	if(flag)
		cout<<"No Answer";
	return 0;
}//这道题还有一种思路，七个皇后已经放好了，排除横向纵向后只剩下唯一一个可能是答案的格子，只需检查该格子的斜向上是否已经摆放了皇后即可。 
