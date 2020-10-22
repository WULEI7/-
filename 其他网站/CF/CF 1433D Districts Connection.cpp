#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
struct node
{
	int ban,num;
}a[5005];
bool cmp(node a,node b)
{
	return a.ban<b.ban;
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].ban;
			a[i].num=i;
		}
		sort(a+1,a+n+1,cmp);
		int flag=0;
		for(int i=2;i<=n;i++)
			if(a[i].ban!=a[i-1].ban)
			{
				flag=1;
				break;
			}
		if(flag==0)
		{
			printf("NO\n");
			continue;
		}
		printf("YES\n");
		for(int i=2;i<=n;i++)
			if(a[i].ban!=a[1].ban)
				printf("%d %d\n",a[1].num,a[i].num);
		int pos=1;
		for(int i=2;i<=n;i++)
			if(a[i].ban!=a[1].ban)
			{
				pos=i;
				break;
			}
		for(int i=2;i<pos;i++)
			printf("%d %d\n",a[pos].num,a[i].num);
	}
	return 0;
}
