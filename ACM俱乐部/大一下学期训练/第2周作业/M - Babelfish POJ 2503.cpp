#include <cstdio>
#include <iostream>
#include <string>
#include <map>
using namespace std;
map<string,string> mp;
map<string,bool> ex;
int main()
{
	char c,s1[12];
	string s,s2;
	while(true)
	{
		if((c=getchar())=='\n')
			break;
		s1[0]=c;
        int i=1;
		while(true)
		{
			c=getchar();
			if(c==' ')
			{
				s1[i]='\0';
				break;
			}
			else
				s1[i++]=c;
		}
		cin>>s2;
		getchar();
		mp.insert({s2,s1});
		ex.insert({s2,true});
	}
	while(cin>>s)
	{
		if(ex[s])
			cout<<mp[s]<<endl;
		else
			cout<<"eh"<<endl;
	}
	return 0;
}
