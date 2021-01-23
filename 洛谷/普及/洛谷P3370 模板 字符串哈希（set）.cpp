#include <iostream>
#include <cstdio>
#include <set>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	set<string> st;
	int n;
	string s;
	cin>>n;
	while(n--)
	{
		cin>>s;
		st.insert(s);
	}
	cout<<st.size()<<endl;
	return 0;
}
