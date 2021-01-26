#include <iostream>
#include <cstdio>
#include <string>
#include <map> 
using namespace std;
string bin[16]={"0000","0001","0010","0011","0100","0101","0110","0111","1000","1001","1010","1011","1100","1101","1110","1111"};
map<string,string> mp;
int main()
{
	int T;
	cin>>T;
	mp["000"]="0";mp["001"]="1";mp["010"]="2";mp["011"]="3";mp["100"]="4";mp["101"]="5";mp["110"]="6";mp["111"]="7";
	while(T--)
	{
		string s16,s2,s8;
		cin>>s16;
		int len1=s16.length();
		for(int i=0;i<len1;i++)
		{
			int t;
			if(s16[i]>='0'&&s16[i]<='9')
				t=s16[i]-'0';
			else
				t=s16[i]-'A'+10;
			s2+=bin[t];
		}//先转换为二进制 
		//cout<<s2<<endl;
		int len2=s2.length();
		int k=len2%3;
		if(k==1) s2.insert(0,"00");len2+=2;
		if(k==2) s2.insert(0,"0");len2++;//补足位数 
		int pos=0;
		while(pos<len2)
		{
			s8+=mp[s2.substr(pos,3)];
			pos+=3;
		}//再转换为八进制 
		pos=0;
		while(s8[pos]=='0') pos++;
		cout<<s8.substr(pos)<<endl;//注意去掉前导零 
	}
	return 0;
}
