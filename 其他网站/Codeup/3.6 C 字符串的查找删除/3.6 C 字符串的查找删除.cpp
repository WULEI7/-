#include <iostream>
#include <cstdio>
#include <string> 
using namespace std;
int main()
{
	string a,b,c;
	getline(cin,a);//����Ҫɾ�����ַ���a 
	for(int i=0;i<a.length();i++)
	{
		if(a[i]>='A'&&a[i]<='Z')
			a[i]+=32;//ASCII�� 
	}//ͳһ��Сд����Ϊ��ĿҪ��ɾ����ʱ�����ִ�Сд 
	while(getline(cin,b))//����ÿһ��b 
	{
		c=b;//��Ҫ����ԭ�ַ���b����Ϊ����������ַ�����СдҪ����ԭ����������ϸ����ĿҪ�� 
		for(int i=0;i<b.length();i++)
		{
			if(b[i]>='A'&&b[i]<='Z')
				b[i]+=32;
		}//��bͳһΪСд�������a����ƥ�� 
		int pos=b.find(a,0);
		//cout<<pos<<endl;//�������-1������ʵpos��ֵ����-1��pos��length���صĶ���unsigned int���޷������������� 
		while(pos<=b.length())//int��unsigned int�Ƚϵ�ʱ���Ĭ��ת�������������ǿ��������Ƚϵģ����ô���ʵ���۲������ 
		{
			//b.replace(pos,a.length(),"");
			b.erase(pos,a.length());
			//�������й�������ͬ�� 
			c.erase(pos,a.length());
			//ͬ������b��c 
			pos=b.find(a,pos);//����������ң������ĵڶ�������ֵ������Ŀ��Ҫ������ʱ����Ҫ�޸���ֵ�����ظ��滻��ѭ������������������ 
		}
		//ɾ���ַ��������еĿո񣨷�����Ψһ��Ҳ�����������find��erase����replace�ķ����� 
		for(unsigned int i=0;i<c.length();i++)
		{
			if(c[i]==' ')
			{
				c.erase(i,1);
				i--;//ע��iҪ��1����Ϊɾ���˿ո�����ַ� 
			}
		}
		cout<<c<<endl;//����任���һ�� 
	}
	return 0;
}
