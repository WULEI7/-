#include<stdio.h>

int main()
{
	int n, l, t;
	
	scanf("%d %d %d",&n,&l,&t);
	
	int balls[105]={0}, v[105]={0}, ischange[105]={0};
	
	int i, j, k;
	
	for(i=1;i<=n;++i)
	{
		scanf("%d",&balls[i]);
		
		v[i] = 1;
	}
	
	for(i=1;i<=t;++i)
	{
		for(j=1;j<=n;++j)
		{
			balls[j] += v[j];
		}
		
		for(j=1;j<=n;++j)
		{
			ischange[j] = 0;
		}
		
		for(j=1;j<=n;++j)
		{
			if(balls[j]==0||balls[j]==l)
			{
				v[j] *= -1;
			}
			else
			{
				if(n==1||ischange[j]==1)
				{
					continue;
				}
				else
				{
					for(k=1;k<=n;++k)
					{
						if(j!=k)
						{
							if(balls[j]==balls[k])
							{
								v[j] *= -1;
								
								v[k] *= -1;
								
								ischange[j] = 1;
								
								ischange[k] = 1;
							}
						}
					}
				}
			}
		}
	}
	
	for(i=1;i<n;++i)
	{
		printf("%d ",balls[i]);
	}
	
	printf("%d\n",balls[n]);
	
	return 0;
}

