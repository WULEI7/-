#include <iostream>
#include <string>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	for(int k=1;k<=t;k++)
	{
		int len;
		cin>>len;
		string s1,s2,s;
		cin>>s1>>s2>>s;
		int flag=0,step=0;
		for(int m=0;m<2*len;m++)//若s1、s2经过循环变为原来的字符串，则不可能 
		{
			string s3;
			for(int i=0;i<len;i++)
			{
				s3+=s2[i];
				s3+=s1[i];
			}
			step++;
			if(s==s3)
			{flag=1;break;}
			s1=s3.substr(0,len);
			s2=s3.substr(len);
		}
		if(flag)
			cout<<k<<" "<<step<<endl;
		else
			cout<<k<<" -1"<<endl;
	}
}
