#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
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
		val[u]++;//此题是符合的单词数加1 
	}
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
	string s;
	while(getline(cin,s))
	{
		if(s=="") break;
        insert(s);
	}
	while(getline(cin,s))
		printf("%d\n",query(s));
	return 0;
}
