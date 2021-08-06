#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
char c[5][5];
int cnt[26],row[26],col[26];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	string a,b;
	cin>>a>>b;
	int len=a.length();
	for(int i=0;i<len;i++)
		cnt[a[i]-'a']=1;
	int x=0,y=0;
	for(int i=0;i<len;i++)
	{
		c[x][y]=a[i];
		y++;
		if(y==5)
		{
			y=0;x++;
		}
	}
	for(int i=0;i<26;i++)
		if(cnt[i]==0)
		{
			cnt[i]=1;
			c[x][y]='a'+i;
			y++;
			if(y==5)
			{
				y=0;x++;
			}
			if(x==5) break;
		}
	/*for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
			cout<<c[i][j];
		cout<<endl;
	}*/
	for(int i=0;i<5;i++)
	for(int j=0;j<5;j++)
	{
		row[c[i][j]-'a']=i;
		col[c[i][j]-'a']=j;
	}
	len=b.length();
	for(int i=0;i<len;i+=2)
	{
		if(i==len-1)
		{
			cout<<b[i];
			continue;
		}
		if(b[i]==b[i+1])
		{
			cout<<b[i]<<b[i+1];
			continue;
		}
		if(cnt[b[i]-'a']==0||cnt[b[i+1]-'a']==0)
		{
			cout<<b[i]<<b[i+1];
			continue;
		}
		if(row[b[i]-'a']==row[b[i+1]-'a']||col[b[i]-'a']==col[b[i+1]-'a'])
		{
			cout<<b[i+1]<<b[i];
			continue;
		}
		cout<<c[row[b[i]-'a']][col[b[i+1]-'a']]<<c[row[b[i+1]-'a']][col[b[i]-'a']];
	}
	return 0;
}
