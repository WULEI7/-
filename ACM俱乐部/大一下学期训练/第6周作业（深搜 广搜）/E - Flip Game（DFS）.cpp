#include <iostream>
#include <cstdio>
using namespace std;
int ans=99,qipan[4][4];
int check()
{
	for(int i=0;i<4;i++)
	for(int j=0;j<4;j++)
		if(qipan[i][j]!=qipan[0][0])
			return 0;
	return 1;
}//检查所有棋子颜色是否相同 
void change(int x,int y)
{
	qipan[x][y]=!qipan[x][y];
	if(x-1>=0) qipan[x-1][y]=!qipan[x-1][y];
	if(y-1>=0) qipan[x][y-1]=!qipan[x][y-1];
	if(x+1<4) qipan[x+1][y]=!qipan[x+1][y];
	if(y+1<4) qipan[x][y+1]=!qipan[x][y+1];
}//对当前位置进行翻动 
void dfs(int t,int k)
{
	if(t==16)
	{
		if(check()==1)
			if(k<ans)
				ans=k;
		return;
	}//每个点最多翻动一次 
	else
	{
		int x=t/4,y=t%4;
		dfs(t+1,k);
		change(x,y);//翻动当前的点 
		dfs(t+1,k+1);
		change(x,y);//注意要翻回来 
	}
}
int main()
{
	char c;
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			scanf("%c",&c);
			if(c=='b')
				qipan[i][j]=0;
			else if(c=='w')
				qipan[i][j]=1;
		}
		getchar();//防止读入回车 
	}
	dfs(0,0);
	if(ans<16)
		printf("%d\n",ans);
	else
		printf("Impossible\n");
	return 0;
}
