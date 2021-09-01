#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,a[10005],ans,ansl,ansr,temp,l,r;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	ans=temp=a[0];
	l=r=0;
	ansl=ansr=a[0];
	for(int i=1;i<n;i++)
	{
		temp+=a[i];
		r=i;
		if(temp<a[i])
		{
			l=i;
			temp=a[i];
		}
		if(temp>ans)
		{
			ans=temp;
			ansl=a[l];
			ansr=a[r];
		}
	}
	if(ans<0)
		printf("%d %d %d\n",0,a[0],a[n-1]);
	else
		printf("%d %d %d\n",ans,ansl,ansr);
	return 0;
}
