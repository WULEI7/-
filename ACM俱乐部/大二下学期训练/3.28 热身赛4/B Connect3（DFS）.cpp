#include <iostream>
#include <cstdio>
#include <set>
using namespace std;
int x,a,b,ans=0,qp[5][5],pos[5];
set<int> st;

bool check(int colour)//判断游戏是否结束 
{
	if(qp[1][1]==colour&&qp[1][1]==qp[1][2]&&qp[1][2]==qp[1][3]||qp[1][2]==colour&&qp[1][2]==qp[1][3]&&qp[1][3]==qp[1][4]||
	   qp[2][1]==colour&&qp[2][1]==qp[2][2]&&qp[2][2]==qp[2][3]||qp[2][2]==colour&&qp[2][2]==qp[2][3]&&qp[2][3]==qp[2][4]||
	   qp[3][1]==colour&&qp[3][1]==qp[3][2]&&qp[3][2]==qp[3][3]||qp[3][2]==colour&&qp[3][2]==qp[3][3]&&qp[3][3]==qp[3][4]||
	   qp[4][1]==colour&&qp[4][1]==qp[4][2]&&qp[4][2]==qp[4][3]||qp[4][2]==colour&&qp[4][2]==qp[4][3]&&qp[4][3]==qp[4][4]||
	   qp[1][1]==colour&&qp[1][1]==qp[2][1]&&qp[2][1]==qp[3][1]||qp[2][1]==colour&&qp[2][1]==qp[3][1]&&qp[3][1]==qp[4][1]||
	   qp[1][2]==colour&&qp[1][2]==qp[2][2]&&qp[2][2]==qp[3][2]||qp[2][2]==colour&&qp[2][2]==qp[3][2]&&qp[3][2]==qp[4][2]||
	   qp[1][3]==colour&&qp[1][3]==qp[2][3]&&qp[2][3]==qp[3][3]||qp[2][3]==colour&&qp[2][3]==qp[3][3]&&qp[3][3]==qp[4][3]||
	   qp[1][4]==colour&&qp[1][4]==qp[2][4]&&qp[2][4]==qp[3][4]||qp[2][4]==colour&&qp[2][4]==qp[3][4]&&qp[3][4]==qp[4][4]||
	   qp[1][1]==colour&&qp[1][1]==qp[2][2]&&qp[2][2]==qp[3][3]||qp[2][2]==colour&&qp[2][2]==qp[3][3]&&qp[3][3]==qp[4][4]||
	   qp[1][2]==colour&&qp[1][2]==qp[2][3]&&qp[2][3]==qp[3][4]||qp[2][1]==colour&&qp[2][1]==qp[3][2]&&qp[3][2]==qp[4][3]||
	   qp[1][4]==colour&&qp[1][4]==qp[2][3]&&qp[2][3]==qp[3][2]||qp[2][3]==colour&&qp[2][3]==qp[3][2]&&qp[3][2]==qp[4][1]||
	   qp[1][3]==colour&&qp[1][3]==qp[2][2]&&qp[2][2]==qp[3][1]||qp[2][4]==colour&&qp[2][4]==qp[3][3]&&qp[3][3]==qp[4][2]) 
		return 1;
	return 0;
}

int state()//状态编码，每格有三种情况：空、黑、白 
{
	int temp=0;
	for(int i=1;i<=4;i++)
	for(int j=1;j<=4;j++)
		temp=temp*3+qp[i][j];
	return temp;
}

void dfs(int colour)//搜索可能的情况 
{
	int sta=state();
	if(st.count(sta)) return;//状态重复 
	st.insert(sta);
	
	if(qp[a][b]==2)//到达最终状态 
	{
		if(check(2))
			ans++;
		return;
	}
	if(check(1)||check(2)||qp[a][b]!=0)
		return;

	for(int i=1;i<=4;i++)
	{
		if(pos[i]==4)//当前列不能再放入石块 
			continue;
		if(colour==1)
		{
			pos[i]++;
			qp[pos[i]][i]=1;
			dfs(2);
			qp[pos[i]][i]=0;
			pos[i]--;
		}
		if(colour==2)
		{
			pos[i]++;
			qp[pos[i]][i]=2;
			dfs(1);
			qp[pos[i]][i]=0;
			pos[i]--;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>x>>a>>b;
	qp[1][x]=1;
	pos[x]++;//在x列放入黑色石块 
	dfs(2);//搜索 
	cout<<ans<<endl;
	return 0;
}
