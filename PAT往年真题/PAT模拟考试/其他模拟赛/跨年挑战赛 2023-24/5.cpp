#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int main()
{
	int ans=0,firstpos=-1,flag=1,pos=0;
	string text;
	string sub="Nian";
	getline(cin,text);
	//cout<<text<<endl;
	while(1)
	{
		pos=text.find(sub,pos);
		//cout<<pos<<endl;
		if(pos==-1) break;
		ans++;
		if(flag)
		{
			firstpos=pos;
			flag=0;
		}
		pos+=sub.length();
	}
	cout<<ans<<" "<<firstpos<<endl;
	return 0;
}
