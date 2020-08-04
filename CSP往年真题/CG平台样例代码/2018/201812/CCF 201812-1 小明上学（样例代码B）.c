#include<stdio.h>

int main()
{
	int r, y, g;//red 红灯 黄灯 绿灯
	
	scanf("%d %d %d",&r,&y,&g);
	
	int n, i, ans = 0;
	
	scanf("%d",&n);
	
	for(i=0;i<n;++i)
	{
		int state, time;
		//0 无灯   1 红灯（加倒计时）   2 黄灯（加倒计时和红灯所有）   3 绿灯（无影响）
		//倒计时/耗时 
		
		scanf("%d %d",&state,&time);
		
		if(state==0)
		{
			ans += time;
		}
		else
		if(state==1)
		{
			ans += time;
		}
		else
		if(state==2)
		{
			ans += (time + r);
		}
		else
		{
			continue;
		}
	}
	
	printf("%d\n",ans);
	
	return 0;
}


