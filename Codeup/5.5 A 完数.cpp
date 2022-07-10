#include <iostream>
#include <cstdio>
#include <cmath> 
using namespace std;
bool isWanshu[10005]; 
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	for(int i=6;i<=10000;i++)//1不是完数 
	{
		int s=sqrt(i);
		int t=1;
		for(int j=2;j<=s;j++)//i本身不算i的因子，所以直接把1加进去，从2开始判断 
		{
			if(i%j==0)
			{
				t+=j;
				t+=i/j;
				if(j*j==i) t-=j;//如果是根号i，只加入一次 
			}
		}
		if(t==i) isWanshu[i]=true;//是完数 
	}
	//以上俗称打表，避免重复计算 
	//输出1-10000之间的完数 
	//for(int i=1;i<=10000;i++)
	//	if(isWanshu[i])
	//		cout<<i<<" "; 
	int n;
	while(cin>>n)
	{
		for(int i=1;i<=n;i++)
			if(isWanshu[i])
				cout<<i<<" ";//这道题这样提交就AC了 
		//如果是PAT平台，必须严格末尾不能多输出空格，要用vector存答案 
		cout<<endl;
	}
	return 0;
}
