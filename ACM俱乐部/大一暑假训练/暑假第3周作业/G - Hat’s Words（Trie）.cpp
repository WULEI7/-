#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
using namespace std;
int trie[1000005][26],val[1000005]={0},pos=1;
void insert(string s)
{
	int u=0,len=s.length();
	for(int i=0;i<len;i++)
	{
		int c=s[i]-'a';
		if(trie[u][c]==0)
			trie[u][c]=pos++;
		u=trie[u][c];
	}
	val[u]=1;
}
int query(string s)
{
	int u=0,len=s.length();
	for(int i=0;i<len;i++)
	{
		int c=s[i]-'a';
		if(trie[u][c]==0)
	        return 0;
	    u=trie[u][c];
	}
	return val[u];
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	vector<string> danci;
	string s;
	while(cin>>s)
	{
    	insert(s);
    	danci.push_back(s);
	}
	int sz=danci.size();
	for(int i=0;i<sz;i++)
	{
		string t=danci[i];
		int len=t.length();
		for(int i=0;i<len-1;i++)//逐位拆分成两个字符串 
		{
			string a,b;
			for(int j=0;j<=i;j++)
				a+=t[j];
			for(int j=i+1;j<len;j++)
				b+=t[j];
			if(query(a)&&query(b))//判断拆分后的两个字符串是否都在单词表中有 
			{
				cout<<t<<endl;
				break;
			}
		}
	}
	return 0;
}
