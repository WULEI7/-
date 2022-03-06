#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int main()
{
	int n,t,k;
	string s;
	cin>>n>>t>>k;
	while(k--)
	{
		cin>>s;
		int len=s.length();
		int ans=0;
		if(s[0]=='f')
			ans-=2;
		if(s[len-1]=='a')
			ans-=1;
		int f;
		f=s.find("aaaaaa");
		if(f!=-1) ans+=3;
		f=s.find("bbbbbb");
		if(f!=-1) ans+=3;
		f=s.find("cccccc");
		if(f!=-1) ans+=3;
		f=s.find("dddddd");
		if(f!=-1) ans+=3;
		f=s.find("eeeeee");
		if(f!=-1) ans+=3;
		f=s.find("ffffff");
		if(f!=-1) ans+=3;
		f=s.find("gggggg");
		if(f!=-1) ans+=3;
		f=s.find("hhhhhh");
		if(f!=-1) ans+=3;
		for(int i=0;i<len-1;i++)
			if(s[i]=='a')
				if(s[i+1]=='e'||s[i+1]=='h')
					ans-=4;
		for(int i=0;i<len-3;)
		{
			int temp=1;
			for(int j=i+1;j<len;j++)
			{
				if(s[j]==s[j-1]+1)
					temp++;
				else
					break;
			}
			if(temp>3) ans+=5;
			i+=temp;
		}
		cout<<ans;
		if(ans>t)
			cout<<"!!!";
		cout<<endl;
	}
	return 0;
}
