#include <iostream>
#include <cstdio>
#include <sstream>
#include <algorithm>
using namespace std;
int n=0,a[100005];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	stringstream ss;
	string s;
	getline(cin,s);
	ss<<s;
	int t,x,y;
	while(ss>>t)
		a[n++]=t;
	sort(a,a+n);
	reverse(a,a+n);
	cin>>x>>y;
	for(int i=0;i<n;i++)
		if(abs(a[i]-x)<=y)
			cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}
