#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
struct node
{
	string name;
	char in[6];
	char out[6];
}per[1005];
bool cmp1(node a,node b)
{
	for(int i=0;i<6;i++)
		if(a.in[i]!=b.in[i])
			return a.in[i]<b.in[i];
	return 0;
}
bool cmp2(node a,node b)
{
	for(int i=0;i<6;i++)
		if(a.out[i]!=b.out[i])
			return a.out[i]>b.out[i];
	return 0;
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,t;
	char c;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>per[i].name;
		t=0;
		for(int j=0;j<8;j++)
		{
			cin>>c;
			if(c>='0'&&c<='9')
				per[i].in[t++]=c;
		}
		t=0;
		for(int j=0;j<8;j++)
		{
			cin>>c;
			if(c>='0'&&c<='9')
				per[i].out[t++]=c;
		}
	}
	sort(per,per+n,cmp1);
	cout<<per[0].name;
	cout<<" ";
	sort(per,per+n,cmp2);
	cout<<per[0].name;
	return 0;
}
