#include<stdio.h>

int main()
{
	int r, y, g;//red ��� �Ƶ� �̵�
	
	scanf("%d %d %d",&r,&y,&g);
	
	int n, i, ans = 0;
	
	scanf("%d",&n);
	
	for(i=0;i<n;++i)
	{
		int state, time;
		//0 �޵�   1 ��ƣ��ӵ���ʱ��   2 �Ƶƣ��ӵ���ʱ�ͺ�����У�   3 �̵ƣ���Ӱ�죩
		//����ʱ/��ʱ 
		
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


