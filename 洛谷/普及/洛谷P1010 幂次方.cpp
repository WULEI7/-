#include <bits/stdc++.h>
using namespace std;
void two(int n)
{
	if(n==0) return;//到n=0时结束递归 
	int temp;
	for(int i=0;i<=15;i++)
		if(pow(2,i)>n)
		{temp=i-1;break;}//temp记录当前小于n的2的最大次方数 
	if(temp==0)
		cout<<"2(0)";
	if(temp==1)
		cout<<"2";
	if(temp>=2)
	{
		cout<<"2(";
		two(temp);
		cout<<")";
	}//当temp>=2时，则需对temp进行处理 
	if(n!=pow(2,temp))
	{
		cout<<"+";
		two(n-pow(2,temp));
	}//对n减去2的最大次方以后的数进行处理 
}
int main()
{
	int n;
	cin>>n;
	two(n);
	return 0;
}
