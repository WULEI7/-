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
};//�������� 
int num[55][55];//ÿ���ľ���� 
char Paint[550][550];//���� 
inline void Draw(int x,int y)//Ϳѻ���� 
{
	int i,j;
	for(i=0;i<6;i++)
		for(j=0;j<7;j++)
			if(Cube[6-i-1][j]!='.')
				Paint[x-i][y+j]=Cube[6-i-1][j];//���÷��� 
}
int main()
{
	int n,m,K=0,L,i,j,x,y;
	scanf("%d%d",&n,&m);
	L=4*m+2*n+1;//���㻭������ 
	for(i=1;i<=n;i++)
	for(j=1;j<=m;j++)
	{
		scanf("%d",&num[i][j]);
		K=max(K,num[i][j]*3+2*(n-i+1)+1);//���㻭������ 
	}
	for(i=1;i<=K;i++)
		for(j=1;j<=L;j++)
			Paint[i][j]='.';//������ʼ�� 
	for(i=1;i<=n;i++)
	for(j=1;j<=m;j++)
	{
		x=K-2*(n-i);
		y=2*(n-i)+4*(j-1)+1;//�������� 
		while(num[i][j]--)
		{
			Draw(x,y);//Ϳѻ 
			x-=3;//���Ϸ� 
		}
	}//�Ӻ���ǰ���������ң������������θ��� 
	for(i=1;i<=K;i++)
	{
		for(j=1;j<=L;j++)
			printf("%c",Paint[i][j]);
		printf("\n");
	}//��ӡ���� 
	return 0;
}
