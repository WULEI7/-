#include <bits/stdc++.h>
using namespace std;
void two(int n)
{
	if(n==0) return;//��n=0ʱ�����ݹ� 
	int temp;
	for(int i=0;i<=15;i++)
		if(pow(2,i)>n)
		{temp=i-1;break;}//temp��¼��ǰС��n��2�����η��� 
	if(temp==0)
		cout<<"2(0)";
	if(temp==1)
		cout<<"2";
	if(temp>=2)
	{
		cout<<"2(";
		two(temp);
		cout<<")";
	}//��temp>=2ʱ�������temp���д��� 
	if(n!=pow(2,temp))
	{
		cout<<"+";
		two(n-pow(2,temp));
	}//��n��ȥ2�����η��Ժ�������д��� 
}
int main()
{
	int n;
	cin>>n;
	two(n);
	return 0;
}
