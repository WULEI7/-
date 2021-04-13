#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
struct node
{
	int r,c;
}a[200005];
bool cmp(node a,node b)
{
	return a.r<b.r;
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int T,n;
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>a[i].r;
		for(int i=0;i<n;i++)
			cin>>a[i].c;
		sort(a,a+n,cmp);
		int ans=0,t1=0,x1=2;//从(1,1)点开始走，t为斜线编号，x为点的行列数之和 
		for(int i=0;i<n;i++)
		{
			int t2=a[i].r-a[i].c,x2=a[i].r+a[i].c;
			if(t1==t2&&x1%2==1||t2-t1==1&&x1%2==0)//在同一条1线上或相邻01线上 
				continue;
			else if(t1==t2&&x1%2==0)//在同一条0线上 
				ans+=(x2-x1)/2;
			else
			{
				if(x1%2==0) t1++;//如果前一个点在0线上，先往左下走，无需步数 
				ans+=(t2-t1+1)/2;
			}
			t1=t2;x1=x2;//继续 
		}
		cout<<ans<<endl;
	}
	return 0;
}
