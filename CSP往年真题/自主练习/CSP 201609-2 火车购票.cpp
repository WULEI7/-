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
		if(p>5) flag=0;
		if(p<=5)//少于5人，查找是否有足够的连续座位 
		{
			for(int i=1;i<=20;i++)
			{
				if(left[i]>=p)
				{
					for(int j=1;j<=5;j++)
						if(seat[i][j]==0)
						{
							p--;
							printf("%d",(i-1)*5+j);//输出当前座位号 
							if(p>0) printf(" ");
							else printf("\n"); 
							left[i]--;//当前一排座位数减1 
							seat[i][j]=1;//当前座位已售出标记 
							if(p==0) break;//注意避免多选座位 
						}
					flag=0;//已找到相邻的座位 
					break;//务必跳出循环，避免重复 
				}
			}
		}
		if(flag==1)//超过5人，或未找到相邻的座位 
		{
			while(p--)
			{
				for(int i=1;i<=20;i++)
				for(int j=1;j<=5;j++)
					if(seat[i][j]==0)
					{
						printf("%d",(i-1)*5+j);//输出当前座位号 
						if(p>0) printf(" ");
						else printf("\n");
						left[i]--;//当前一排座位数减1 
						seat[i][j]=1;//当前座位已售出标记 
					}
			}
		}
	}
	return 0;
}
