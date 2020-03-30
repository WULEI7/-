#include <iostream>
using namespace std;
int buy(int sum,int bot,int cap)
{
	int temp=bot/2+cap/3;
	if(temp==0) return sum;//temp记录现有的空瓶和盖子能够兑换水的瓶数，如果为0则结束递归 
	sum+=temp;
	bot=bot%2+temp;
	cap=cap%3+temp;
	return buy(sum,bot,cap);//将现有空瓶和盖子进行兑换，然后进行下一轮 
}
int main()
{
	int sum,bot,cap;
	cin>>sum;
	bot=cap=sum;
	cout<<buy(sum,bot,cap);
	return 0;
}
