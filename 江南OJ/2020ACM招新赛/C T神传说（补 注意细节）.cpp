#include <bits/stdc++.h>
using namespace std;
char paper[101][101];
int main()
{
	int n,m,i,j,flag=1,i0,j0,temp=0;
	memset(paper,'E',sizeof(paper));//注意清空的位置 
	cin>>n>>m;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			cin>>paper[i][j];
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
		{
			if(i==n)
			{
				cout<<"fAKe";
				return 0;
			}//到下边界还没找到 
			if(paper[i][j]=='X'&&j<m)
			{i0=i;j0=j;goto label0;}
		}
	label0:
	for(j=j0;j<=m;j++)
		if(paper[i0][j]=='X') temp++;
	if(temp==1||temp%2==0) flag=0;//细节 
	else
	{
		for(j=j0;j<=j0+temp-1;j++)
			paper[i0][j]='E';
		if(paper[i0+1][j0+temp/2]=='E')
		{
			flag=0;
			goto label1;
		}//细节 
		else
		{
			for(i=i0+1;i<=n;i++)
			{
				if(paper[i][j0+temp/2]=='X')
					paper[i][j0+temp/2]='E';
				else break;
			}
			for(i=1;i<=n;i++)
				for(j=1;j<=m;j++)
					if(paper[i][j]=='X')
					{
						flag=0;
						goto label1;
					}
		}
	}
	label1:
	if(flag==1) cout<<"AuthentiC";
	if(flag==0) cout<<"fAKe";
	return 0;
}
