#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;
int sub=0;
struct node
{
	string s;
	int grade[4],rank[4],best;
	char ans;
}c[2005];
bool cmp(node a,node b)
{
	return a.grade[sub]>b.grade[sub];
}
map<string,int> mp;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>c[i].s>>c[i].grade[1]>>c[i].grade[2]>>c[i].grade[3];
		c[i].grade[0]=c[i].grade[1]+c[i].grade[2]+c[i].grade[3];
	}
	for(int i=0;i<=3;i++)
	{
		sub=i;
		sort(c,c+n,cmp);
		c[0].rank[i]=1;
		for(int j=1;j<n;j++)
		{
			if(c[j].grade[i]==c[j-1].grade[i])
				c[j].rank[i]=c[j-1].rank[i];
			else
				c[j].rank[i]=j+1;
		}
	}
	for(int i=0;i<n;i++)
	{
		mp[c[i].s]=i;
		int best=0,temp=2005;
		for(int j=0;j<=3;j++)
		{
			if(c[i].rank[j]<temp)
			{
				temp=c[i].rank[j];
				best=j;
			}
		}
		c[i].best=temp;
		if(best==0)
			c[i].ans='A';
		else if(best==1)
			c[i].ans='C';
		else if(best==2)
			c[i].ans='M';
		else
			c[i].ans='E';
	}
	string s;
	for(int i=0;i<m;i++)
	{
		cin>>s;
		if(mp.count(s))
		{
			cout<<c[mp[s]].best<<" "<<c[mp[s]].ans;
		}
		else
			cout<<"N/A";
		if(i!=m-1)
			cout<<endl;
	}
	return 0;
}
