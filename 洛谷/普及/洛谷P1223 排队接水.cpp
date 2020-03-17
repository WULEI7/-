#include <cstdio>
#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;
struct person
{
	int time;
	int num;
};
bool cmp(person a,person b)
{
	if(a.time<b.time)
		return true;
	else if(a.time==b.time)
		return a.num<b.num;
	else
		return false;
}
int main()
{
	ios::sync_with_stdio(false);
	int n;
	person t[1005];
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>t[i].time;
		t[i].num=i;
	}
	sort(t+1,t+n+1,cmp);
	double ans=0;
	for(int i=1;i<=n;i++)
	{
		ans+=t[i].time*(n-i);
		cout<<t[i].num;
		if(i!=n) cout<<" ";
	}
	cout<<endl;
	cout<<fixed<<setprecision(2)<<ans/n<<endl;
	return 0;
}
