#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
	int seat[21][6]={0},left[21],n,p;
	for(int i=1;i<=20;i++)
		left[i]=5;
	cin>>n;
	while(n--)
	{
		cin>>p;
		int flag=1;
		if(p<=5)
		{
			for(int i=1;i<=20;i++)
			{
				if(left[i]>=p)
				{
					for(int j=1;j<=5;j++)
						if(seat[i][j]==0)
						{
							p--;
							printf("%d",(i-1)*5+j);
							if(p>0) printf(" ");
							else printf("\n"); 
							left[i]--;
							seat[i][j]=1;
							if(p==0) break;
						}
					flag=0;
					break;
				}
			}
		}
		if(flag==1)
		{
			for(int i=1;i<=20;i++)
			{
				for(int j=1;j<=5;j++)
				{
					if(seat[i][j]==0)
					{
						p--;
						printf("%d",(i-1)*5+j);
						if(p>0) printf(" ");
						else printf("\n");
						left[i]--;
						seat[i][j]=1;
						if(p==0) break;
					}
				}
				if(p==0) break;
			}
		}
	}
	return 0;
}
