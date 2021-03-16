#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n,m;
struct node
{
	string name;
	int points,wins,losses,draws,scored,allowed;
}team[35];
bool cmp(node a,node b)
{
	if(a.points>b.points)
		return 1;
	if(a.points<b.points)
		return 0;
	if(a.scored-a.allowed>b.scored-b.allowed)
		return 1;
	if(a.scored-a.allowed<b.scored-b.allowed)
		return 0;
	if(a.scored>b.scored)
		return 1;
	if(a.scored<b.scored)
		return 0;
	if(a.name.compare(b.name)<0)//×ÖµäÐòa<b 
		return 1;
	return 0;
}
void update(string ss,int p,int s,int a)
{
	for(int i=0;i<n;i++)
		if(team[i].name==ss)
		{
			team[i].points+=p;
			team[i].scored+=s;
			team[i].allowed+=a;
			if(p==3)
				team[i].wins++;
			else if(p==1)
				team[i].draws++;
			else if(p==0)
				team[i].losses++;
			break;
		}
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int T;
	cin>>T;
	for(int t=1;t<=T;t++)
	{
		cin>>n>>m;
		for(int i=0;i<n;i++)
		{
			cin>>team[i].name;
			team[i].points=team[i].wins=team[i].losses=team[i].draws=team[i].scored=team[i].allowed=0;
		}
		for(int i=0;i<m;i++)
		{
			string a,b;
			int c,d;
			cin>>a>>c>>b>>d;
			if(c>d)
			{
				update(a,3,c,d);
				update(b,0,d,c);
			}
			else if(c==d)
			{
				update(a,1,c,d);
				update(b,1,d,c);
			}
			else if(c<d)
			{
				update(a,0,c,d);
				update(b,3,d,c);
			}
		}
		sort(team,team+n,cmp);
		printf("Group %d:\n",t);
		for(int i=0;i<n;i++)
			printf("%s %d %d %d %d %d %d\n",team[i].name.c_str(),team[i].points,team[i].wins,team[i].losses,team[i].draws,team[i].scored,team[i].allowed);
		printf("\n");
	}
	return 0;
}
