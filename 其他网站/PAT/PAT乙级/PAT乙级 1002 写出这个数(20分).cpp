#include <iostream>
#include <cstdio>
#include <string>
#include <stack>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	string a[10]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
	int t=0;
	string s;
	cin>>s;
	int len=s.length();
	for(int i=0;i<len;i++)
		t+=s[i]-'0';
	if(t==0)
		cout<<"ling"<<endl;
	else
	{
		stack<string> ans;
		while(t>0)
		{
			ans.push(a[t%10]);
			t/=10;
		}
		cout<<ans.top();
		ans.pop();
		while(!ans.empty())
		{
			cout<<" "<<ans.top();
			ans.pop();
		}
		cout<<endl;
	}
	return 0;
}
