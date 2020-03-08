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
}//stand函数对字符串进行标准化 
map<string,int> cnt;//cnt记录标准化后的单词重复数 
vector<string> word;//word存放原单词 
vector<string> ans;//ans存放输出的单词 

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
	}//依次输入每个单词，存入word中，并用cnt计算重复数 
	for(int i=0;i<word.size();i++)
		if(cnt[stand(word[i])]==1) ans.push_back(word[i]);
	sort(ans.begin(),ans.end());
	for(int i=0;i<ans.size();i++)
		cout<<ans[i]<<endl;//将符合的单词存入ans中并输出 
	return 0;
}
