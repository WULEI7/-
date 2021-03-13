#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int bg[300005];
struct node
{
	int v,w,flag;
}sp[300005];
bool cmp(node a,node b)
{
	return a.v<b.v;
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m,ans=0;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>sp[i].v>>sp[i].w;
		sp[i].flag=1;
	}
	sort(sp,sp+n,cmp);
	for(int i=0;i<m;i++)
		cin>>bg[i];
	sort(bg,bg+m);
	for(int i=0;i<m;i++)
	{
		int maxn=0,pos;
		for(int j=0;j<n;j++)
		{
			if(sp[j].v>bg[i])
				break;
			if(sp[j].w>maxn&&sp[j].flag==1)
			{
				maxn=sp[j].w;
				pos=j;
			}
		}
		ans+=maxn;
		sp[pos].flag=0;
	}
	cout<<ans<<endl;
	return 0;
}
