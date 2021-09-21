#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int n,t;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>t;
		cout<<1;//不能有前导零 
		if(t<10)
			cout<<0;
		cout<<i;//控制字典序 
		while(t--)
			cout<<0;//控制大小顺序 
		cout<<" ";
	}
	return 0;
}
