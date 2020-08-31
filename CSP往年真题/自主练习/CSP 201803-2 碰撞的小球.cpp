#include <cstdio>
#include <iostream>
using namespace std;
struct node
{
	int v,pos;
}ball[105];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,L,t,T=1;
	cin>>n>>L>>t;
	for(int i=1;i<=n;i++)
	{
		ball[i].v=1;
		cin>>ball[i].pos;
	}
	while(T<=t)
	{
		for(int i=1;i<=n;i++)
		{
			ball[i].pos+=ball[i].v;
			if(ball[i].pos==0||ball[i].pos==L)
				ball[i].v=-ball[i].v;
		}
		for(int i=1;i<n;i++)
		for(int j=i+1;j<=n;j++)
			if(ball[i].pos==ball[j].pos)
			{
				ball[i].v=-ball[i].v;
				ball[j].v=-ball[j].v;
			}
		T++;
	}
	printf("%d",ball[1].pos);
	for(int i=2;i<=n;i++)
		printf(" %d",ball[i].pos);
	printf("\n");
	return 0;
}
