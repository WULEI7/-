#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
struct node
{
	int t,s;
};
bool cmp(node x,node y)
{
	if(x.s==y.s)
		return x.t<y.t;
	else
		return x.s>y.s;
}

int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int ans,n,time[1005]={0};
	node h[1005];
	cin>>ans>>n;
	for(int i=0;i<n;i++)
		cin>>h[i].t;
	for(int i=0;i<n;i++)
		cin>>h[i].s;
	sort(h,h+n,cmp);
	for(int i=0;i<n;i++)
	{
		int j;
		for(j=h[i].t;j>0;j--)
		{
			if(time[j]==0)
			{
				time[j]=1;
				break;
			}
		}
		if(j==0)
			ans-=h[i].s;
	}//优先考虑罚钱多的游戏，尽量放到最靠近截止的时间来完成，如无法完成则扣掉相应的钱 
	cout<<ans<<endl;
	return 0;
}
