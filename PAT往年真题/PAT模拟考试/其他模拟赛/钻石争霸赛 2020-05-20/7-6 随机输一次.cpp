#include <iostream>
#include <cstdio>
#include <string>
#include <map>
using namespace std;
string s[3]={"ChuiZi","JianDao","Bu"};
map<string,int> mp;
int c[11];
int main()
{
	int n,time=0,temp=0;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>c[i];
	mp["ChuiZi"]=0;
	mp["JianDao"]=1;
	mp["Bu"]=2;
	string t;
	while(cin>>t)
	{
		if(t=="End") break;
		time++;
		if(time<=c[temp])
			cout<<s[(mp[t]+2)%3]<<endl;//Ó® 
		if(time>c[temp])
		{
			cout<<s[(mp[t]+1)%3]<<endl;//Êä 
			time=0;
			temp=(temp+1)%n;//×¢ÒâÑ­»· 
		}
	}
	return 0;
}
