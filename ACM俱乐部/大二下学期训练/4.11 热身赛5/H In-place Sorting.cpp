#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;
	string s[10005];
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>s[i];
	int len=s[0].length();
	for(int j=0;j<len;j++)
		if(s[0][j]=='9')
			s[0][j]='6';//����һ����������9����6 
	int flag=1;
	for(int i=1;i<n;i++)
	{
		len=s[i].length();
		if(len<s[i-1].length())
		{
			flag=0;
			break;
		}//������ȱ�ǰһ����С���򲻿��� 
		if(len>s[i-1].length())
		{
			for(int j=0;j<len;j++)
				if(s[i][j]=='9')
					s[i][j]='6';
			continue; 
		}//������ȱ�ǰһ������������9����6���� 
		for(int j=0;j<len;j++)
			if(s[i][j]=='6')
				s[i][j]='9';
		if(s[i-1].compare(s[i])>0)
		{
			flag=0;
			break;
		}//���������6����9����ǰһ����С���򲻿��� 
		for(int j=0;j<len;j++)
		{
			if(s[i][j]=='9')
			{
				s[i][j]='6';
				if(s[i-1].compare(s[i])>0)
					s[i][j]='9';
			}
		}//��ǰ�����԰�9����6 
		for(int j=len-1;j>=0;j--)
		{
			if(s[i][j]=='9')
			{
				s[i][j]='6';
				if(s[i-1].compare(s[i])>0)
					s[i][j]='9';
			}
		}//�Ӻ���ǰ�԰�9����6 
	}
	if(flag==0)
		cout<<"impossible"<<endl;
	if(flag==1)
	{
		cout<<"possible"<<endl;
		for(int i=0;i<n;i++)
			cout<<s[i]<<endl;
	}
	return 0;
}
