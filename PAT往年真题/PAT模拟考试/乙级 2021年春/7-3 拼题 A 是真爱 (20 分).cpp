#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	string s;
	getline(cin,s);
	int len=s.length();
	for(int i=0;i<len;i++)
		if(s[i]=='P')
			s[i]+=32;
	s+=".";
	int ans=0;
	int pos=s.find("pintia");
	if(pos==0&&(s[pos+6]=='.'||s[pos+6]==','||s[pos+6]==' ') || pos>0&&(s[pos-1]=='.'||s[pos-1]==','||s[pos-1]==' ')&&(s[pos+6]=='.'||s[pos+6]==','||s[pos+6]==' '))
		ans++;
	while(pos>=0)
	{
		pos=s.find("pintia",pos+1);
		if(pos>0&&(s[pos-1]=='.'||s[pos-1]==','||s[pos-1]==' ')&&(s[pos+6]=='.'||s[pos+6]==','||s[pos+6]==' '))
			ans++;
	}
	cout<<ans<<endl;
	if(ans==0)
		cout<<"wu gan"<<endl;
	if(ans>=1&&ans<=3)
		cout<<"you ai"<<endl;
	if(ans>=4)
		cout<<"zhen ai la"<<endl;
	return 0;
}
