#include <iostream>
#include <cstdio>
#include <string> 
using namespace std;
int main()
{
	//freopen("test0.in","r",stdin);
	//freopen("test1.out","w",stdout);
	//�������ض����������Դ��ļ���������� 
	//��ʱ���Ի��߾������к����ã�������������˽� 
	string s,a,b;
	while(getline(cin,s))
	{
		getline(cin,a);
		getline(cin,b);
		//��Ϊ�ַ����п����пո����Ҫ��getline��� 
		int pos=s.find(a,0);
		while(pos<=s.length())
		{
			s.replace(pos,a.length(),b);
			//pos=s.find(a,pos+1);
			//�������У�����ڶ�������дpos+1������ѭ����
			//����������һ��������
			/*
			man
			man
			woman
			*/ 
			//����Ϊʲô����ѭ�� 
			pos=s.find(a,pos+b.length());
			//�����ͱ������������ 
			//�����Ĳ���������ôд������Ҫɾ���ĳ���֮�ֻ࣬���Լ����ô���ʵ���۲� 
		}
		cout<<s<<endl;
	}
	return 0;
}
