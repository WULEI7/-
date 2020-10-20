#include <iostream>
#include <string>
using namespace std;
int main()
{
	int t;
	string s;
	scanf("%d",&t);
	while(t--)
	{
		cin>>s;
		int len=s.length();
		if(len>=2&&s[len-2]=='p'&&s[len-1]=='o')
		{
			cout<<"FILIPINO"<<endl;
			continue;
		}
		if(len>=4&&s[len-4]=='d'&&s[len-3]=='e'&&s[len-2]=='s'&&s[len-1]=='u')
		{
			cout<<"JAPANESE"<<endl;
			continue;
		}
		if(len>=4&&s[len-4]=='m'&&s[len-3]=='a'&&s[len-2]=='s'&&s[len-1]=='u')
		{
			cout<<"JAPANESE"<<endl;
			continue;
		}
		if(len>=5&&s[len-5]=='m'&&s[len-4]=='n'&&s[len-3]=='i'&&s[len-2]=='d'&&s[len-1]=='a')
		{
			cout<<"KOREAN"<<endl;
			continue;
		}
	}
	return 0;
}
