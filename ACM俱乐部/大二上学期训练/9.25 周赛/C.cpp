#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
struct node
{
	int d,h;
}opt[105];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t,n,x;
	cin>>t;
	while(t--)
	{
		int maxn=0,first=0,flag=0;
		cin>>n>>x;
		for(int i=0;i<n;i++)
		{
			cin>>opt[i].d>>opt[i].h;
			if(opt[i].d>first)
				first=opt[i].d;
			if(opt[i].d-opt[i].h>maxn)
				maxn=opt[i].d-opt[i].h;
			if(opt[i].d-opt[i].h>0||opt[i].d>=x)//×¢ÒâÏ¸½Ú 
				flag=1;
		}
		if(flag==0)
		{
			printf("-1\n");
			continue;
		}
		if(first>=x)
		{
			printf("1\n");
			continue;
		}
		if(maxn<first)
		{
			if((x-first)%maxn)
				printf("%d\n",(x-first)/maxn+2);
			else
				printf("%d\n",(x-first)/maxn+1);
		}
		else
		{
			if(x%maxn)
				printf("%d\n",x/maxn+1);
			else
				printf("%d\n",x/maxn);
		}
	}
}
