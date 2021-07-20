#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
struct node
{
	string name,num;
	int score;
}a[105];
bool cmp(node a,node b)
{
	return a.score>b.score;
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i].name>>a[i].num>>a[i].score;
	sort(a,a+n,cmp);
	cout<<a[0].name<<" "<<a[0].num<<endl;
	cout<<a[n-1].name<<" "<<a[n-1].num<<endl;
	return 0;
}
