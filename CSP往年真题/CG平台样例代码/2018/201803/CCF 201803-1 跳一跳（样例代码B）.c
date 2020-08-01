#include<stdio.h>

int main()
{
	int bounce = 1;
	
	int ans = 0;
	
	int num;
	
	while(scanf("%d",&num)!=EOF)
	{						
		if(num==1)
		{
			ans += 1;
			
			bounce = 1;
		}
		else
		if(num==2)
		{
			ans += 2*bounce;
			
			bounce++;
		}
		else
		if(num==0) 
		{
			break;
		}
	}
	
	printf("%d\n",ans);
	
	return 0;
}

