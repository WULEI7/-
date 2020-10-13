#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
int trie[10005][26],val[10005]={0},pos=1;
void insert(string s)
{
	int u=0,len=s.length();
	for(int i=0;i<len;i++)
	{
		int c=s[i]-'a';
		if(trie[u][c]==0)
			trie[u][c]=pos++;
		u=trie[u][c];
		val[u]++;//符合前缀的单词数加1 
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
	int n; 
	string s[60];
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>s[i];
        insert(s[i]);
	}
	for(int i=0;i<n;i++)
	{
		int len=s[i].length();
		for(int j=1;j<=len;j++)
		{
			if(query(s[i].substr(0,j))==1)
			{
				cout<<s[i].substr(0,j)<<endl;
				break;
			}
		}
	}//找到当前单词最长的不是其他单词前缀的子串 
	return 0;
}
