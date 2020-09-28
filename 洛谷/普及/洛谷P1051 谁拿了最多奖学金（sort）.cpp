#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
struct node
{
	string name;
	int qm,bj;
	char gb,xb;
	int lw,tot=0,num;
	
}stu[105];
bool cmp(node a,node b)
{
	return a.tot!=b.tot ? a.tot>b.tot : a.num<b.num;
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,cnt=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		stu[i].num=i;
		cin>>stu[i].name>>stu[i].qm>>stu[i].bj>>stu[i].gb>>stu[i].xb>>stu[i].lw;
		if(stu[i].qm>80&&stu[i].lw>=1)
			stu[i].tot+=8000;
		if(stu[i].qm>85&&stu[i].bj>80)
			stu[i].tot+=4000;
		if(stu[i].qm>90)
			stu[i].tot+=2000;
		if(stu[i].qm>85&&stu[i].xb=='Y')
			stu[i].tot+=1000;
		if(stu[i].bj>80&&stu[i].gb=='Y')
			stu[i].tot+=850;
		cnt+=stu[i].tot;
	}
	sort(stu+1,stu+n+1,cmp);
	cout<<stu[1].name<<endl<<stu[1].tot<<endl<<cnt<<endl;
	return 0;
}
