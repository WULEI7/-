#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int n,m,g,f,a,na,pa,paa,paar;
struct node
{
	int num,loc;
}l[1005];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		l[i].num=i;
		cin>>l[i].loc;
	}
	cin>>g;
	int temp=0;
	while(g--)
	{
		cin>>f>>a>>na>>pa>>paa>>paar;
		if(na==0)//计算节点亲和性无要求na=0（20分） 
		{
			for(int i=1;i<=f;i++)
			{
				temp=temp%n+1;
				cout<<temp<<" ";
			}
		}
		else//未完成 
		{
			temp=temp%n+1;
			for(int i=1;i<=f;i++)
			{
				if(l[temp].loc==na)
					cout<<temp<<" ";
				else
				{
					temp=temp%n+1;
					i--;
				}
			}
		}
		cout<<endl;
	}
	return 0;
}
