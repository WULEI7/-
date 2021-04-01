#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <map>
using namespace std;
/*
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
string bin[16]={"0000","0001","0010","0011","0100","0101","0110","0111","1000","1001","1010","1011","1100","1101","1110","1111"};
map<string,string> mp;
int main()
{
	mp["0000"]="0";mp["0001"]="1";mp["0010"]="2";mp["0011"]="3";mp["0100"]="4";mp["0101"]="5";mp["0110"]="6";mp["0111"]="7";
	mp["1000"]="8";mp["1001"]="9";mp["1010"]="a";mp["1011"]="b";mp["1100"]="c";mp["1101"]="d";mp["1110"]="e";mp["1111"]="f";
	int T;
	cin>>T;
	for(int t=1;t<=T;t++)
	{
		string a,b,c,a2,b2,c2;
		cin>>a>>b;
		int len1=a.length();
		for(int i=0;i<len1;i++)
		{
			int t;
			if(a[i]>='0'&&a[i]<='9')
				t=a[i]-'0';
			else
				t=a[i]-'a'+10;
			a2+=bin[t];
		}
		int len2=b.length();
		for(int i=0;i<len2;i++)
		{
			int t;
			if(b[i]>='0'&&b[i]<='9')
				t=b[i]-'0';
			else
				t=b[i]-'a'+10;
			b2+=bin[t];
		}//先转换为二进制 
		while(a2[0]=='0')
			a2.erase(0,1);
		while(b2[0]=='0')
			b2.erase(0,1);//去前导零 
		//cout<<a2<<endl<<b2<<endl;
		int lena=a2.length(),lenb=b2.length();
		int lenm=min(lena,lenb);
		for(int i=0;i<lenm;i++)
		{
			if(a2[i]==b2[i])
				c2+=a2[i];
			else
				break;
		}//求二进制下的最近公共祖先 
		while(c2.length()%4)
			c2="0"+c2;//补前导零 
		while(c2.length()>0)
		{
			c+=mp[c2.substr(0,4)];
			c2.erase(0,4);
		}//二进制转十六进制 
		printf("Case #%d: %s",t,c.c_str());
		printf("\n\n");
	}
	return 0;
}
