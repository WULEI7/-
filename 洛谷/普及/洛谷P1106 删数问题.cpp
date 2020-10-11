#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;
	string s;
	cin>>s>>n;
	int len=s.length();
	for(int i=0;i<n;i++)
	{
		int flag=0;
		for(int j=0;j<len-1;j++)
			if(s[j]>s[j+1])
			{
				s.erase(j,1);
				flag=1;
				break;
			}//贪心删除前比后大的数字 
		if(flag==0)
			s.erase(len-1,1);//如果没了则删末尾 
		len--;
	}
	for(int i=0;i<len;i++)
	{
		if(s[i]!='0') break;
		s.erase(i,1);
		i--;
	}//删除前导零 
	if(s.length()>0)
		cout<<s<<endl;
	else
		cout<<"0"<<endl;//注意细节 
	return 0;
}
