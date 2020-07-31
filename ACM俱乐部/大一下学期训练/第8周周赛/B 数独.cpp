#include <cstdio>
using namespace std;
int main()
{
	int n,x[9][9];
	scanf("%d",&n);
	while(n--)
	{
		for(int i=0;i<9;i++)
			for(int j=0;j<9;j++)
				scanf("%1d",&x[i][j]);
		for(int i=0;i<9;i++)
		{
			for(int j=0;j<9;j++)
			{
				if(x[i][j]==2)
					x[i][j]=3;
				printf("%d",x[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}
