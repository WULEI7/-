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
}//�������������ɫ�Ƿ���ͬ 
void change(int x,int y)
{
	qipan[x][y]=!qipan[x][y];
	if(x-1>=0) qipan[x-1][y]=!qipan[x-1][y];
	if(y-1>=0) qipan[x][y-1]=!qipan[x][y-1];
	if(x+1<4) qipan[x+1][y]=!qipan[x+1][y];
	if(y+1<4) qipan[x][y+1]=!qipan[x][y+1];
}//�Ե�ǰλ�ý��з��� 
void dfs(int t,int k)
{
	if(t==16)
	{
		if(check()==1)
			if(k<ans)
				ans=k;
		return;
	}//ÿ������෭��һ�� 
	else
	{
		int x=t/4,y=t%4;
		dfs(t+1,k);
		change(x,y);//������ǰ�ĵ� 
		dfs(t+1,k+1);
		change(x,y);//ע��Ҫ������ 
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
		getchar();//��ֹ����س� 
	}
	dfs(0,0);
	if(ans<16)
		printf("%d\n",ans);
	else
		printf("Impossible\n");
	return 0;
}
