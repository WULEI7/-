#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm> 
using namespace std;
struct node
{
	string s;
	int grade[4],rank[4],best;
	char ans;
}stu[2005];
int sub=0;
bool cmp(node a,node b)
{
	return a.grade[sub]>b.grade[sub];
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>stu[i].s>>stu[i].grade[1]>>stu[i].grade[2]>>stu[i].grade[3];
		stu[i].grade[0]=stu[i].grade[1]+stu[i].grade[2]+stu[i].grade[3];
	}
	for(int i=0;i<4;i++)
	{
		sub=i;
		sort(stu,stu+n,cmp);
		stu[0].rank[i]=1;
		for(int j=1;j<n;j++)
		{
			if(stu[j].grade[i]==stu[j-1].grade[i])
				stu[j].rank[i]=stu[j-1].rank[i];
			else
				stu[j].rank[i]=j+1;
		}
	}
	map<string,int> mp;
	for(int i=0;i<n;i++)
	{
		mp[stu[i].s]=i;
		int best=0,temp=2005;
		for(int j=0;j<4;j++)
		{
			if(stu[i].rank[j]<temp)
			{
				temp=stu[i].rank[j];
				best=j;
			}
		}
		stu[i].best=temp;
		if(best==0)
			stu[i].ans='A';
		else if(best==1)
			stu[i].ans='C';
		else if(best==2)
			stu[i].ans='M';
		else
			stu[i].ans='E';
	}
	string s;
	for(int i=0;i<m;i++)
	{
		cin>>s;
		if(mp.count(s))
			cout<<stu[mp[s]].best<<" "<<stu[mp[s]].ans<<endl;
		else
			cout<<"N/A"<<endl;
	}
	return 0;
}
