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
		}//将s中字母存入vec，每个字母数量存入size 
		
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
		}//如果t中有s中没有的字母，则不可能完成 
		
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
					}*///超时，要用二分查找 
				int j=upper_bound(vec[ch].begin(),vec[ch].end(),pos)-vec[ch].begin();
				pos=vec[ch][j];
			}//如果当前位置后面有当前需要的字母 
			else
			{
				ans++;
				pos=vec[ch][0];
			}//否则次数加1，从s的首部重新开始 
		}
		cout<<ans<<endl;
	}
	return 0;
}
