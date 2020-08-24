#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,a[1005],flag=1,ans;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	for(int i=0;i<n;i++)//注意有可能是所有数字都相同的特殊情况 
	{
		int left=0,right=0;
		for(int j=0;j<n;j++)
		{
			if(a[j]<a[i]) left++;
			if(a[j]>a[i]) right++;
		}
		if(left==right)
		{
			flag=0;
			ans=a[i];
			break;
		}
	}
	if(flag==1)
		printf("-1\n");
	else
		printf("%d\n",ans);
	return 0;
}
