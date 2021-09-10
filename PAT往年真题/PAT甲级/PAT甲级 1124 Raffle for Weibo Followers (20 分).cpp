#include <iostream>
#include <cstdio>
#include <set>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int m,n,s,temp=0;
	string t;
	set<string> st;
	cin>>m>>n>>s;
	while(m--)
	{
		cin>>t;
		if(st.count(t)==0)
			temp++;
		else continue;//没加上这句也能过，测试数据有漏洞 
		if(temp-s>=0&&(temp-s)%n==0)
		{
			cout<<t<<endl;
			st.insert(t);
		}
	}
	if(st.size()==0)
		cout<<"Keep going..."<<endl;
	return 0;
}
