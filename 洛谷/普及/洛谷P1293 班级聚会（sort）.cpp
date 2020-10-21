#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
struct node
{
	int num,dis,tot;
	string name;
}city[160];
bool cmp(node a,node b)
{
	return a.tot!=b.tot ? a.tot<b.tot:a.dis<b.dis;
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t=0;
	while(cin>>city[t].num>>city[t].dis>>city[t].name)
		t++;
	for(int i=0;i<t;i++)
	{
		city[i].tot=0;
		for(int j=0;j<t;j++)
			city[i].tot+=abs(city[j].dis-city[i].dis)*city[j].num;
	}
	sort(city,city+t,cmp);
	cout<<city[0].name<<" "<<city[0].tot<<endl;
	return 0;
}
