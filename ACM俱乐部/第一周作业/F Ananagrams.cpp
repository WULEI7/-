#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cctype>
#include <map>
using namespace std;
string stand(string &str)
{
	string ans=str;
	for(int i=0;i<ans.length();i++)
		ans[i]=tolower(ans[i]);
	sort(ans.begin(),ans.end());
	return ans;
}//stand�������ַ������б�׼�� 
map<string,int> cnt;//cnt��¼��׼����ĵ����ظ��� 
vector<string> word;//word���ԭ���� 
vector<string> ans;//ans�������ĵ��� 

int main()
{
	std::ios::sync_with_stdio(false); 
	int n=0;
	string s;
	while(cin>>s)
	{
		if(s[0]=='#') break;
		word.push_back(s);
		string s1=stand(s);
		if(!cnt.count(s1)) cnt[s1]=0;
		cnt[s1]++;
	}//��������ÿ�����ʣ�����word�У�����cnt�����ظ��� 
	for(int i=0;i<word.size();i++)
		if(cnt[stand(word[i])]==1) ans.push_back(word[i]);
	sort(ans.begin(),ans.end());
	for(int i=0;i<ans.size();i++)
		cout<<ans[i]<<endl;//�����ϵĵ��ʴ���ans�в���� 
	return 0;
}
