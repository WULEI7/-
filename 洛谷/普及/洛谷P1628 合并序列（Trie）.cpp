#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
int trie[1000005][26],val[1000005]={0},pos=1,t;
string s;
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
	val[u]++;//因为此题需要完整单词而不是前缀，所以此句写在for循环外面 
}
int query(string s)
{
	int u=0,len=s.length();
	for(int i=0;i<len;i++)
	{
		int c=s[i]-'a';
		if(trie[u][c]==0)
	        return 0;
	    u=t=trie[u][c];
	}
	return val[u];
}
void dfs(int t)
{
		while(val[t]--)
			cout<<s<<endl;
	for(int i=0;i<26;i++)
	{
		if(trie[t][i])
		{
			s+='a'+i;
			dfs(trie[t][i]);
			s=s.substr(0,s.length()-1);
		}
	}
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>s;
        insert(s);
	}
	cin>>s;
	query(s); 
	dfs(t);
	return 0;
}
