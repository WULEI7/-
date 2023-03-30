#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int k,m,flag=1;
	long long n,a,b;
	cin>>k>>m>>n;
	for(int i=1;i<=m;i++)
	{
		cin>>a>>b;
		if(a==0||k/a*b>=n)//注意a可以为0 
		{
			cout<<i<<" ";
			flag=0;
		}
	}
	if(flag==1)
		cout<<"-1";
	return 0;
}
