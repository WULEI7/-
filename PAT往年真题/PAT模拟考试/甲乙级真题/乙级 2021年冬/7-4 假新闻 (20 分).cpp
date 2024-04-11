#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int t=10000;//将观点值加上t变为正数 
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m,a[10005],tot[10005]={0},cnt[20005],ans,maxn=0;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		memset(cnt,0,sizeof(cnt));
		for(int j=1;j<=n;j++)
		{
			cin>>a[j];
			cnt[a[j]+t]++;
		}
		int minn=10005;
		for(int j=1;j<=n;j++)
			if(cnt[a[j]+t]<minn)
				minn=cnt[a[j]+t];//找到内容相同最少的报道数量 
		for(int j=1;j<=n;j++)
			if(cnt[a[j]+t]==minn)
				tot[j]++;//所有相同报道数量等于最少数量的即为疑似假新闻，在tot中计数 
	}
	for(int i=1;i<=10000;i++)
	{
		if(tot[i]>maxn)
		{
			ans=i;
			maxn=tot[i];
		}//找到tot计数最大的网站编号 
	}
	cout<<ans<<endl;
	return 0;
}
