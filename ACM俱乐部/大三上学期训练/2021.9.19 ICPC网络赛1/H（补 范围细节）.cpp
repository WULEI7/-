#include <iostream>
#include <cstdio>
#include <string>
#include <vector> 
#include <algorithm>
using namespace std;
vector<int> v1[21005],v2[21005];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int m,n,l,k,id,x,y,z;
	string s;
	double a,b,c;
	cin>>m>>n;
	for(int i=1;i<=m;i++)
	{
		cin>>id>>a>>b>>c;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>id>>s;
		if(s=="203")
		{
			cin>>x>>y>>z;
			v1[x].emplace_back(y);
			v1[x].emplace_back(z);
			v1[y].emplace_back(x);
			v1[y].emplace_back(z);
			v1[z].emplace_back(x);
			v1[z].emplace_back(y);
			v2[x].emplace_back(id);
			v2[y].emplace_back(id);
			v2[z].emplace_back(id);
		}
		if(s=="102")
		{
			cin>>x>>y;
			v1[x].emplace_back(y);
			v1[y].emplace_back(x);
			v2[x].emplace_back(id);
			v2[y].emplace_back(id);
		}
	}
	for(int i=1;i<=m;i++)
	{
		sort(v1[i].begin(),v1[i].end());
		sort(v2[i].begin(),v2[i].end());
	}
	cin>>l;
	while(l--)
	{
		cin>>k;
		if(k>=21005||k<0)//¼ÓÉÏÕâ¾äAC 
		{
			cout<<k<<endl<<"[]"<<endl<<"[]"<<endl;
			continue;
		}
		cout<<k<<endl;
		int size=v1[k].size();
		if(size==0)
			cout<<"[]"<<endl;
		else
		{
			int temp=v1[k][0];
			cout<<"["<<temp;
			for(int i=1;i<size;i++)
			{
				if(v1[k][i]!=temp)
				{
					temp=v1[k][i];
					cout<<","<<temp;
				}
				else
					continue;
			}
			cout<<"]"<<endl;
		}
		size=v2[k].size();
		if(size==0)
			cout<<"[]"<<endl;
		else
		{
			int temp=v2[k][0];
			cout<<"["<<temp;
			for(int i=1;i<size;i++)
			{
				if(v2[k][i]!=temp)
				{
					temp=v2[k][i];
					cout<<","<<temp;
				}
				else
					continue;
			}
			cout<<"]"<<endl;
		}
	}
	return 0;
}
