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
}//用四位二进制整数检测每个对象是否在北岸 
int safe(int location)
{
	if(goat(location)==cabbage(location)&&goat(location)!=farmer(location))
		return 0;//羊吃白菜 
	if(goat(location)==wolf(location)&&goat(location)!=farmer(location))
		return 0;//狼吃羊 
	return 1;//其他状态是安全的 
}//安全状态的判断 
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int route[16];//记录路径 
	memset(route,-1,sizeof(route));
	queue<int> moveto;//记录多重选择 
	route[0]=0;
	moveto.push(0);//初始状态加入moveto和route 
	while(!moveto.empty()&&route[15]==-1)//队列非空&&还没到终止状态 
	{
		int state=moveto.front();
		moveto.pop();//出队当前状态 
		for(int i=1;i<=8;i<<=1)//分别判断能否带羊、菜、狼、农夫自己过河（位运算） 
		{
			if(((state&i)!=0)==((state&0x08)!=0))//如果农夫和要带的物品在同侧 
			{
				int newstate=state^(0x08|i);
				if(safe(newstate)&&route[newstate]==-1)//newstate安全且未访问过 
				{
					moveto.push(newstate);
					route[newstate]=state;//标记状态newstate已访问过，且是从安全状态state过渡来的 
				}
			}
		}
	}
	if(route[15]!=-1)//如果能够到达最终状态，输出结果 
	{
		stack<int> temp;//结果是倒过来的，用栈保存以顺序输出 
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
