#include<stdio.h>

int main()
{
	long long int r, y, g;//红 黄 绿
	
	scanf("%lld %lld %lld",&r,&y,&g);
	
	long long int n, i, ans = 0, route;
	
	route = r + y + g;
	//绿灯-黄灯-红灯 
	
	scanf("%lld",&n);
	
	for(i=0;i<n;++i)
	{
		long long int state, time;
		//0 无灯   1 红灯（加倒计时）   2 黄灯（加倒计时和红灯所有）   3 绿灯（无影响）
		//倒计时/耗时 
		
		scanf("%lld %lld",&state,&time);
		
		if(state==0)
		{
			ans += time;
		}
		else
		if(state==1)
		{
			time = route - time;//变成一周期已走时间 
			
			time += ans;//总共已走时间 
			
			time %= route;//该周期位置 
			
			if(time<g)
			{
				continue;
			}
			else
			{
				ans += route - time;//变为剩余时间 
			}
		}
		else
		if(state==2)
		{
			time = route - time -r;
			
			time += ans;
			
			time %= route;
			
			if(time<g)
			{
				continue;
			}
			else
			{
				ans += route - time;
			}
		}
		else
		{
			time = route - time - r - y;
			
			time += ans;
			
			time %= route;
			
			if(time<g)
			{
				continue;
			}
			else
			{
				ans += route - time; 
			}
		}
	}
	
	printf("%lld\n",ans);
	
	return 0;
}

