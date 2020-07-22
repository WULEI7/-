#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
int trie[1000005][2],val[1000005]={0},pos=1,flag=0;
void insert(string s)
{
	int u=0,len=s.length();
	for(int i=0;i<len;i++)
	{
		int c=s[i]-'0';//注意这里是0不是a 
		if(trie[u][c]==0)
			trie[u][c]=pos++;
		else if(i==len-1)//判断当前字符串是否为其他字符串的前缀 
			flag=1;
		u=trie[u][c];
		if(val[u])//判断是否有其他字符串是当前字符串的前缀 
			flag=1;
	}
	val[u]=1;
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	string s;
	int t=0;
	while(cin>>s)
	{
		t++;
		pos=1;
		memset(trie,0,sizeof(trie));
		memset(val,0,sizeof(val));
		flag=0;
		insert(s);
		while(cin>>s)
		{
			if(s=="9") break;
			insert(s);
		}
		if(flag==0)
			printf("Set %d is immediately decodable\n",t);
		else if(flag==1)
			printf("Set %d is not immediately decodable\n",t);
	}
	return 0;
}
