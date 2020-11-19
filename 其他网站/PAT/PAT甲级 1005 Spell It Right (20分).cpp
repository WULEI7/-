#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;
string num[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	string s;
	cin>>s;
	int len=s.length();
	int sum=0;
	for(int i=0;i<len;i++)
		sum+=s[i]-'0';
	stack<int> sta;
	while(sum)
	{
		sta.push(sum%10);
		sum/=10;
	}
	int size=sta.size();
	if(size==0)
		cout<<"zero";
	else
	{
		cout<<num[sta.top()];
		sta.pop();
		size--;
		while(size)
		{
			cout<<" "<<num[sta.top()];
			sta.pop();
			size--;
		}
	}
	return 0;
}
