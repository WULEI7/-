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
	}//������ 
	map<int,int> pos;
	for(int i=1;i<=n;i++)
		pos[d[i]]=i;//��¼�������ڶ��е�λ�� 
	while(m--)
	{
		cin>>a>>x;
		if(x=="and")//a��b�Ƿ�Ϊ�ֵܽ�� 
		{
			cin>>b>>y>>z;
			if(pos[a]==0||pos[b]==0||pos[a]==pos[b])//���a��b�����ڣ�����a��b��ͬһ����� 
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
			if(z=="root")//a�Ƿ�Ϊ���ڵ� 
			{
				if(pos[a]==1)
					cout<<"1";
				else
					cout<<"0";
			}
			else if(z=="parent")//a�Ƿ�Ϊb�ĸ��׽�� 
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
			else if(z=="left")//a�Ƿ�Ϊb�����ӽ�� 
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
			else if(z=="right")//a�Ƿ�Ϊb�����ӽ�� 
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
