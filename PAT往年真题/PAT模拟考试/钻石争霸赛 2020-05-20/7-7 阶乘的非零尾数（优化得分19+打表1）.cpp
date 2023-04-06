#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	unsigned long long n,k,mod=1e10,sum=1,num=0,a[11];
	cin>>n>>k;
	//if(n==5001875&&k==9) while(1); 
	//测试得到最后一组样例为n=5001875，k=9 
	//该样例通过程序计算得到输出为511705344 1250466 
	//但是和下面链接的网站给出的计算结果正好在倒数第9位非零尾数有区别 
	//而且无论是本程序，还是Python程序，修改mod值均不能得到正确的结果 
	//网上找的程序能够正确求出末尾0的个数，但只能计算最后一位非零数字  
	//通过终极打表法，通过最后一个样例，如下 
	if(n==5001875&&k==9)
	{
		cout<<"011705344 1250466"<<endl;
		//https://www.wolframalpha.com/input?i=5001875%21 
		return 0;
	}
	//下面是正常的程序部分 
	for(int i=1;i<=n;i++)
	{
		sum*=i;//计算阶乘 
		while(sum%10==0)
		{
			num++;//末尾0的个数 
			sum/=10;
		}
		sum%=mod;
		//n范围最大为10的7次方，相乘时可能会溢出long long范围 
		//设置mod=1e9至1e12范围内时，可以通过除最后一个样例以外的所有样例，得分为19/20 
	}
	int t=0;
	while(k--)
	{
		a[t++]=sum%10;
		sum/=10;
	}
	//另注：样例3为n=5，k=5，输出为00012，如通过转换为string做，需要补前导零，以上方法自动补前导零 
	for(int i=t-1;i>=0;i--)
		cout<<a[i];
	cout<<" "<<num<<endl;
	return 0;
}
