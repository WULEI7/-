#include <cstdio>
#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main()
{
	string s,str,ss;
	int f,n;
	cin>>s>>f>>n;
	int len=s.length();
	if(f==0)
	{
		for(int i=0;i<len;i++)
			if(isupper(s[i]))
				s[i]=tolower(s[i]);
	}//不区分大小写 
	while(n--)
	{
		cin>>str;
		ss=str;//注意保存原字符串 
		if(f==0)
		{
			len=str.length();
			for(int i=0;i<len;i++)
				if(isupper(str[i]))
					str[i]=tolower(str[i]);
		}//不区分大小写 
		int pos=str.find(s,0);//注意返回值转化为int才是-1 
		if(pos>=0)
			cout<<ss<<endl;
	}
	return 0;
}
