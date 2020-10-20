#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
using namespace std;
int farmer(int location)
{
	if(0!=(location&0x08))
		return 1;
	else return 0;
}
int wolf(int location)
{
	if(0!=(location&0x04))
		return 1;
	else return 0;
}
int cabbage(int location)
{
	if(0!=(location&0x02))
		return 1;
	else return 0;
}
int goat(int location)
{
	if(0!=(location&0x01))
		return 1;
	else return 0;
}//����λ�������������ÿ�������Ƿ��ڱ��� 
int safe(int location)
{
	if(goat(location)==cabbage(location)&&goat(location)!=farmer(location))
		return 0;//��԰ײ� 
	if(goat(location)==wolf(location)&&goat(location)!=farmer(location))
		return 0;//�ǳ��� 
	return 1;//����״̬�ǰ�ȫ�� 
}//��ȫ״̬���ж� 
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int route[16];//��¼·�� 
	memset(route,-1,sizeof(route));
	queue<int> moveto;//��¼����ѡ�� 
	route[0]=0;
	moveto.push(0);//��ʼ״̬����moveto��route 
	while(!moveto.empty()&&route[15]==-1)//���зǿ�&&��û����ֹ״̬ 
	{
		int state=moveto.front();
		moveto.pop();//���ӵ�ǰ״̬ 
		for(int i=1;i<=8;i<<=1)//�ֱ��ж��ܷ���򡢲ˡ��ǡ�ũ���Լ����ӣ�λ���㣩 
		{
			if(((state&i)!=0)==((state&0x08)!=0))//���ũ���Ҫ������Ʒ��ͬ�� 
			{
				int newstate=state^(0x08|i);
				if(safe(newstate)&&route[newstate]==-1)//newstate��ȫ��δ���ʹ� 
				{
					moveto.push(newstate);
					route[newstate]=state;//���״̬newstate�ѷ��ʹ������ǴӰ�ȫ״̬state�������� 
				}
			}
		}
	}
	if(route[15]!=-1)//����ܹ���������״̬�������� 
	{
		stack<int> temp;//����ǵ������ģ���ջ������˳����� 
		for(int i=15;i>=0;i=route[i])
		{
			temp.push(i);
			if(i==0) break;
		}
		while(!temp.empty())
		{
			cout<<temp.top()<<" ";
			temp.pop();
		}
		cout<<endl;
	}
	return 0;
}
