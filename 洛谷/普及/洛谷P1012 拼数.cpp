#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
bool cmp(string a,string b)
{
	return a+b>b+a;
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;
	string num[25],ans;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>num[i];
	sort(num,num+n,cmp);
	for(int i=0;i<n;i++)
		ans+=num[i];
	cout<<ans<<endl;
	return 0;
}
