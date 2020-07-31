#include <iostream>
using namespace std;

int Euler(int n)
{
	int ans=1,temp=1;//用ans记录欧拉函数的值，用temp记录上一次除的数 
	while(n>1)
	{
		for(int i=2;i<=n;i++)
			if(n%i==0)//除完一次即进入下一次循环，所以不需要判断i是否为素数 
			{
				n/=i;
				if(i==temp)
					ans*=i;//如果是已经除过的数，则ans乘上i 
				else
				{
					ans*=i-1;
					temp=i;
				}//如果是没有除过的数，则ans乘上i-1 
				break;
			}
	}
	return ans;
}

int main()
{
	int n,ans;
	cin>>n;
	for(int i=1;i<n;i++)
		ans+=Euler(i);
	cout<<2*ans+1<<endl;
	return 0;
}
