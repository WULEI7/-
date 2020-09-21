#include<cstdio>
#include<iostream>

using namespace std;

int main()
{
	int t;
	
	scanf("%d",&t);
	
	while(t--)
	{
		int n;
		
		scanf("%d",&n);
		
		long long int a[51][51]={0}, fk[4][4]={0};
		
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=n;++j)
			{
				scanf("%lld",&a[i][j]);
			}
		}
		
		long long int km = 0;
		
		for(int i=1;i<=3;++i)
		{
			for(int j=1;j<=3;++j)
			{
				scanf("%lld",&fk[i][j]);
				
				km += fk[i][j];
			}
		}
		
		long long int prec[51][51]={0}, nowc[51][51]={0};
		
		int flag = -1;
		
		while(flag<=0)
		{
			if(flag == -1)
			{
				for(int i=1;i<=n;++i)
				{
					for(int j=1;j<=n;++j)
					{
						prec[i][j] = 0;
						
						for(int k=1;k<=3&&k<=n-i+1;++k)
						{
							for(int l=1;l<=3&&l<=n-j+1;++l)
							{
								prec[i][j] += a[i+k-1][j+l-1]*fk[k][l]; 
							}
						}
						
						prec[i][j] /= km;
					}
				}
				
				flag = 0;
			}
			else
			{
				for(int i=1;i<=n;++i)
				{
					for(int j=1;j<=n;++j)
					{
						nowc[i][j] = 0;
						
						for(int k=1;k<=3&&k<=n-i+1;++k)
						{
							for(int l=1;l<=3&&l<=n-j+1;++l)
							{
								nowc[i][j] += prec[i+k-1][j+l-1]*fk[k][l]; 
							}
						}
						
						nowc[i][j] /= km;
					}
				}
				
				int t = 1;
				
				for(int i=1;i<=n;++i)
				{
					for(int j=1;j<=n;++j)
					{
						if(nowc[i][j]!=prec[i][j])
						{
							t = 0;
						}
					}
				}
				
				if(t==1)
				{
					flag++;
					
					break;
				}
				else
				{
					for(int i=1;i<=n;++i)
					{
						for(int j=1;j<=n;++j)
						{
							prec[i][j] = nowc[i][j];
						}
					}
				}
			}
		}
		
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<n;++j)
			{
				printf("%lld ",nowc[i][j]);
			}
			
			printf("%lld\n",nowc[i][n]);
		}
	}
	
	return 0;
}
