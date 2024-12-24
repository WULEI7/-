#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;
bool isBig(char c)
{
	if(c>='A'&&c<='Z')
		return true;
	return false;
}
bool isSma(char c)
{
	if(c>='a'&&c<='z')
		return true;
	return false;
}
bool isNum(char c)
{
	if(c>='0'&&c<='9')
		return true;
	return false;
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int w,t;
	string s;
	cin>>w>>t>>s;
	int len=s.length();
	s="A"+s;
	vector<int> v,ans;

	for(int i=1;i<=len;i++)
	{
		if(isBig(s[i-1])&&isSma(s[i]))
		{
			v.emplace_back(27);
		}
		if(isBig(s[i-1])&&isNum(s[i]))
		{
			v.emplace_back(28);
		}
		if(isSma(s[i-1])&&isBig(s[i]))
		{
			v.emplace_back(28);
			v.emplace_back(28);
		}
		if(isSma(s[i-1])&&isNum(s[i]))
		{
			v.emplace_back(28);
		}
		if(isNum(s[i-1])&&isBig(s[i]))
		{
			v.emplace_back(28);
		}
		if(isNum(s[i-1])&&isSma(s[i]))
		{
			v.emplace_back(27);
		}
		if(isBig(s[i]))
			v.emplace_back(s[i]-'A');
		if(isSma(s[i]))
			v.emplace_back(s[i]-'a');
		if(isNum(s[i]))
			v.emplace_back(s[i]-'0');
	}
	if(v.size()%2==1)
		v.emplace_back(29);
	int size=v.size();
	//for(int i=0;i<size;i++)
	//	cout<<v[i]<<" ";
	for(int i=0;i<size-1;i+=2)
		ans.emplace_back(v[i]*30+v[i+1]);
	
	if(t==-1)
	{
		//ans.insert(ans.begin(),w);
		//size=ans.size();
		//for(int i=0;i<size;i++)
		//	cout<<ans[i]<<endl;
		//for(int i=size;i<w;i++)
		//	cout<<"900"<<endl;
		size=ans.size()+1;
		int temp=size%w;
		if(temp!=0)
			size=size+w-temp;
		ans.insert(ans.begin(),size);
		for(int i=1;i<=w-temp;i++)
			ans.emplace_back(900);
	}
	if(t==0)
	{
		
	}
	if(t==1)
	{
		
	}
	if(t==2)
	{
		
	}
	for(int i=0;i<size;i++)
		cout<<ans[i]<<endl;
	return 0;
}