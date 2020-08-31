#include <cstdio>
#include <iostream>
using namespace std;
int c,a[16][11],b[5][5];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	for(int i=1;i<=15;i++)
	for(int j=1;j<=10;j++)
		cin>>a[i][j];
	for(int i=1;i<=4;i++)
	for(int j=1;j<=4;j++)
		cin>>b[i][j];
	cin>>c;
	int dis=15;
	for(int i=0;i<4;i++)
	{
		int temp,up,down,j;
		for(j=4;j>=1;j--)
			if(b[j][i+1]==1)
				break;
		up=j;
		if(up==0) continue;
		for(j=1;j<=15;j++)
			if(a[j][c+i]==1)
				break;
		down=j;
		temp=down-up-1;
		if(temp<dis)
			dis=temp;
	}
	for(int i=1;i<=4;i++)
	for(int j=1;j<=4;j++)
		if(b[i][j]==1)
			a[i+dis][c+j-1]=1;
	for(int i=1;i<=15;i++)
	{
		printf("%d",a[i][1]);
		for(int j=2;j<=10;j++)
			printf(" %d",a[i][j]);
		printf("\n");
	}
	return 0;
}
