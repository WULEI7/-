#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		vector<int> vec[26];
		int size[26]={0};
		string s,t;
		cin>>s>>t;
		int len1=s.length(),len2=t.length();
		for(int i=0;i<len1;i++)
		{
			vec[s[i]-'a'].push_back(i);
			size[s[i]-'a']++;
		}//��s����ĸ����vec��ÿ����ĸ��������size 
		
		int flag=0;
		for(int i=0;i<len2;i++)
			if(size[t[i]-'a']==0)
			{
				flag=1;
				break;
			}
		if(flag==1)
		{
			cout<<"-1"<<endl;
			continue;
		}//���t����s��û�е���ĸ���򲻿������ 
		
		int ans=1,pos=-1;
		for(int i=0;i<len2;i++)
		{
			int ch=t[i]-'a';
			if(pos<vec[ch][size[ch]-1])
			{
				/*for(int j=0;j<=size[ch]-1;j++)
					if(vec[ch][j]>pos)
					{
						pos=vec[ch][j];
						break;
					}*///��ʱ��Ҫ�ö��ֲ��� 
				int j=upper_bound(vec[ch].begin(),vec[ch].end(),pos)-vec[ch].begin();
				pos=vec[ch][j];
			}//�����ǰλ�ú����е�ǰ��Ҫ����ĸ 
			else
			{
				ans++;
				pos=vec[ch][0];
			}//���������1����s���ײ����¿�ʼ 
		}
		cout<<ans<<endl;
	}
	return 0;
}
