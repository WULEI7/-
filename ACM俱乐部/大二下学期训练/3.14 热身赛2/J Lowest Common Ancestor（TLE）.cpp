#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
char num[16]={'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
long long h_to_d(string s)//十六进制转十进制 
{
	int len=s.length();
	long long ans=0,temp=1;
	for(int i=0;i<len;i++)
	{
		long long t;
		if(s[len-1-i]>='0'&&s[len-1-i]<='9')
			t=s[len-1-i]-'0';
		else
			t=s[len-1-i]-'a'+10;
		ans+=t*temp;
		temp*=16;
	}
	return ans;
}
/*
string d_to_h(long long n)//十进制转十六进制 
{
	stack<char> s;
	string ans;
	while(n!=0)
	{
		s.push(num[n%16]);
		n/=16;
	}
	if(s.empty())
		ans="0";
	while(!s.empty())
	{
		ans+=s.top();
		s.pop();
	}
	return ans;
}
*/
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int T;
	cin>>T;
	for(int t=1;t<=T;t++)
	{
		string a,b;
		cin>>a>>b;
		long long aa,bb,cc;
		aa=h_to_d(a);
		bb=h_to_d(b);
		while(1)
		{
			if(aa>bb) aa>>=1;
			if(bb>aa) bb>>=1;
			if(aa==bb)
			{
				cc=aa;
				break;
			}
		}
		//c=d_to_h(cc);
		printf("Case #%d: ",t);
		char c[20];
		int pos=0;
		while(cc!=0)
		{
			c[pos++]=num[cc%16];
			cc/=16;
		}
		for(int i=pos-1;i>=0;i--)
			printf("%c",c[i]);
		printf("\n\n");
	}
	return 0;
}
