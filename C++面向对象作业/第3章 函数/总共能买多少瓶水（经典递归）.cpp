#include <iostream>
using namespace std;
int buy(int sum,int bot,int cap)
{
	int temp=bot/2+cap/3;
	if(temp==0) return sum;//temp��¼���еĿ�ƿ�͸����ܹ��һ�ˮ��ƿ�������Ϊ0������ݹ� 
	sum+=temp;
	bot=bot%2+temp;
	cap=cap%3+temp;
	return buy(sum,bot,cap);//�����п�ƿ�͸��ӽ��жһ���Ȼ�������һ�� 
}
int main()
{
	int sum,bot,cap;
	cin>>sum;
	bot=cap=sum;
	cout<<buy(sum,bot,cap);
	return 0;
}
