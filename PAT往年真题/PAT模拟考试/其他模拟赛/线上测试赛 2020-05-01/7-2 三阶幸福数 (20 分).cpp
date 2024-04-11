#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int vis[10005];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,t;
	cin>>n;
	while(n--)
	{
		memset(vis,0,sizeof(vis));
		cin>>t;
		vis[t]=1;
		int temp=0,time=0,flag=1;
		while(t!=1)
		{
			while(t>0)
			{
				int x=t%10;
				temp+=x*x*x;
				t/=10;
			}
			if(vis[temp])
			{
				cout<<temp<<endl;
				flag=0;
				break;
			}
			time++;
			vis[temp]=1;
			t=temp;
			temp=0;
		}
		if(flag==1)
			cout<<time<<endl;
	}
	return 0;
}
