#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
struct node
{
	int begin,end;
	bool operator < (const node b) const
	{
		return end<b.end;
	}
}p[2005];
int main()
{
	int n,h,m,s;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d:%d:%d",&h,&m,&s);
		p[i].begin=h*3600+m*60+s;
		scanf("%d:%d:%d",&h,&m,&s);
		p[i].end=h*3600+m*60+s;
	}
	sort(p,p+n);
	int sta=p[0].end,ans=1;
	for(int i=1;i<n;i++)
	{
		if(p[i].begin>=sta)
		{
			ans++;
			sta=p[i].end;
		}
	}
	cout<<ans<<endl;
	return 0;
}
