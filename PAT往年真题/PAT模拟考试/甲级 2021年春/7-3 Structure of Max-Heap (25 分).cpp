#include <iostream>
#include <cstdio>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0); 
	int n,m,a,b,d[1005];
	string x,y,z,s,t;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>d[i];
		for(int j=i;j>1;j/=2)
		{
			if(d[j]>d[j/2])
				swap(d[j],d[j/2]);
			else
				break;
		}
	}//建最大堆 
	map<int,int> pos;
	for(int i=1;i<=n;i++)
		pos[d[i]]=i;//记录各数字在堆中的位置 
	while(m--)
	{
		cin>>a>>x;
		if(x=="and")//a和b是否为兄弟结点 
		{
			cin>>b>>y>>z;
			if(pos[a]==0||pos[b]==0||pos[a]==pos[b])//结点a或b不存在，或者a和b是同一个结点 
			{
				cout<<"0";
				continue;
			}
			if(pos[a]/2==pos[b]/2)
				cout<<"1";
			else
				cout<<"0";
		}
		else//(x=="is") 
		{
			cin>>y>>z;
			if(z=="root")//a是否为根节点 
			{
				if(pos[a]==1)
					cout<<"1";
				else
					cout<<"0";
			}
			else if(z=="parent")//a是否为b的父亲结点 
			{
				cin>>s>>b;
				if(pos[a]==0||pos[b]==0)
				{
					cout<<"0";
					continue;
				}
				if(pos[a]==pos[b]/2)
					cout<<"1";
				else
					cout<<"0";
			}
			else if(z=="left")//a是否为b的左子结点 
			{
				cin>>s>>t>>b;
				if(pos[a]==0||pos[b]==0)
				{
					cout<<"0";
					continue;
				}
				if(pos[a]==pos[b]*2)
					cout<<"1";
				else
					cout<<"0";
			}
			else if(z=="right")//a是否为b的右子结点 
			{
				cin>>s>>t>>b;
				if(pos[a]==0||pos[b]==0)
				{
					cout<<"0";
					continue;
				}
				if(pos[a]==pos[b]*2+1)
					cout<<"1";
				else
					cout<<"0";
			}
		}
	}
	return 0;
}
