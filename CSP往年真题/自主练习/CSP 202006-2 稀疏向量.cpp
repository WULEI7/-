#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
vector<pair<int,int> > num;//注意“>”之间的空格，否则编译出错 
int main()
{
	
	int n,a,b,x,v;
	scanf("%d%d%d",&n,&a,&b);
	for(int i=0;i<a;i++)
	{
		scanf("%d%d",&x,&v);
		num.push_back({x,v});
	}
	int t=0,size=num.size();
	long long ans=0;
	for(int i=0;i<b;i++)
	{
		scanf("%d%d",&x,&v);
		while(t<size)
		{
			if(num[t].first==x)
			{
				ans+=v*num[t].second;
				break;
			}
			else if(num[t].first>x)
				break;
			t++;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
