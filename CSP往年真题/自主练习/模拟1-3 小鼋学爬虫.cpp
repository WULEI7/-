#include <cstdio>
#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main()
{
	string s,str,ss;
	int f,n;
	cin>>s>>f>>n;
	int len=s.length();
	if(f==0)
	{
		for(int i=0;i<len;i++)
			if(isupper(s[i]))
				s[i]=tolower(s[i]);
	}//�����ִ�Сд 
	while(n--)
	{
		cin>>str;
		ss=str;//ע�Ᵽ��ԭ�ַ��� 
		if(f==0)
		{
			len=str.length();
			for(int i=0;i<len;i++)
				if(isupper(str[i]))
					str[i]=tolower(str[i]);
		}//�����ִ�Сд 
		int pos=str.find(s,0);//ע�ⷵ��ֵת��Ϊint����-1 
		if(pos>=0)
			cout<<ss<<endl;
	}
	return 0;
}
