#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int t=10000;//���۵�ֵ����t��Ϊ���� 
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
				minn=cnt[a[j]+t];//�ҵ�������ͬ���ٵı������� 
		for(int j=1;j<=n;j++)
			if(cnt[a[j]+t]==minn)
				tot[j]++;//������ͬ���������������������ļ�Ϊ���Ƽ����ţ���tot�м��� 
	}
	for(int i=1;i<=10000;i++)
	{
		if(tot[i]>maxn)
		{
			ans=i;
			maxn=tot[i];
		}//�ҵ�tot����������վ��� 
	}
	cout<<ans<<endl;
	return 0;
}
