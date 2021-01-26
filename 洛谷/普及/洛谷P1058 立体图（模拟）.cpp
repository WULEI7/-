#include <iostream>
#include <cstdio>
using namespace std;
char Cube[6][8]=
{
	"..+---+",
	"./   /|",
	"+---+ |",
	"|   | +",
	"|   |/.",
	"+---+.."
};//单个方块 
int num[55][55];//每格积木数量 
char Paint[550][550];//画布 
inline void Draw(int x,int y)//涂鸦函数 
{
	int i,j;
	for(i=0;i<6;i++)
		for(j=0;j<7;j++)
			if(Cube[6-i-1][j]!='.')
				Paint[x-i][y+j]=Cube[6-i-1][j];//放置方块 
}
int main()
{
	int n,m,K=0,L,i,j,x,y;
	scanf("%d%d",&n,&m);
	L=4*m+2*n+1;//计算画布列数 
	for(i=1;i<=n;i++)
	for(j=1;j<=m;j++)
	{
		scanf("%d",&num[i][j]);
		K=max(K,num[i][j]*3+2*(n-i+1)+1);//计算画布行数 
	}
	for(i=1;i<=K;i++)
		for(j=1;j<=L;j++)
			Paint[i][j]='.';//画布初始化 
	for(i=1;i<=n;i++)
	for(j=1;j<=m;j++)
	{
		x=K-2*(n-i);
		y=2*(n-i)+4*(j-1)+1;//计算坐标 
		while(num[i][j]--)
		{
			Draw(x,y);//涂鸦 
			x-=3;//向上放 
		}
	}//从后往前，从左往右，从下往上依次覆盖 
	for(i=1;i<=K;i++)
	{
		for(j=1;j<=L;j++)
			printf("%c",Paint[i][j]);
		printf("\n");
	}//打印画布 
	return 0;
}
