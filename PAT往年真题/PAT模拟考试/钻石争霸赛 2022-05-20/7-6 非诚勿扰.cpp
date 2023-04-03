#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
const double e=2.718;//这里一开始写成了int 
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,s,maxn=0,standard=0,best=0,choice=0,flag=1;
	cin>>n;
	int r=n/e;
	for(int i=1;i<=n;i++)
	{
		cin>>s;
		if(i<=r)
		{
			if(s>maxn)
			{
				maxn=s;
				best=i;
				standard=s;
			}
		}
		else//i>r 
		{
			if(s>maxn)
			{
				maxn=s;
				best=i;
			}
			if(s>standard&&flag==1)
			{
				flag=0;
				choice=i;
			}
		}
	}
	//if(choice==0) while(1);
	//说明输出错误的答案样例是选了的 
	cout<<choice<<" "<<best<<endl;
	return 0;
}
