#include<stdio.h>

int main()
{
	long long int r, y, g;//�� �� ��
	
	scanf("%lld %lld %lld",&r,&y,&g);
	
	long long int n, i, ans = 0, route;
	
	route = r + y + g;
	//�̵�-�Ƶ�-��� 
	
	scanf("%lld",&n);
	
	for(i=0;i<n;++i)
	{
		long long int state, time;
		//0 �޵�   1 ��ƣ��ӵ���ʱ��   2 �Ƶƣ��ӵ���ʱ�ͺ�����У�   3 �̵ƣ���Ӱ�죩
		//����ʱ/��ʱ 
		
		scanf("%lld %lld",&state,&time);
		
		if(state==0)
		{
			ans += time;
		}
		else
		if(state==1)
		{
			time = route - time;//���һ��������ʱ�� 
			
			time += ans;//�ܹ�����ʱ�� 
			
			time %= route;//������λ�� 
			
			if(time<g)
			{
				continue;
			}
			else
			{
				ans += route - time;//��Ϊʣ��ʱ�� 
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

