#include <iostream>
#include <cstdio>
using namespace std;

class String
{
	public:
		String();//Ĭ�Ϲ��캯�� 
		String(const char *c);//���ع��캯����char�ַ������� 
		String(const String &str);//�������캯����String���� 
		String Substr(int pos,int n);//��ȡ�Ӵ� 
		void Clear();//����ַ��� 
		bool Insert(String str,int pos);//�����ַ� 
		bool Delete(int pos,int n);//ɾ���ַ� 
		int Find(String pat,int pos);//���ַ����д�λ��pos��ʼѰ���Ӵ�pat������λ�ã���δ�ҵ�����-1 
		friend void getnext(String pat);//��Ԫ������KMP�㷨getnext���� 
		friend int kmp(String str,String pat);//��Ԫ������KMP�㷨���ĺ��� 
		int Length();//��ȡ���ĳ��� 
		void Print();//��ӡ�ַ��� 
		String& operator +=(String str);//�����������+=����ʵ���ַ�����ƴ�� 
		friend ostream & operator << (ostream &out,String &str);//�����������<<����ʵ����cout��ӡ�ַ��� 
	private:
		char *s;
		int length;
};//String���ʵ�� 


String::String()
{
	s=new char[1];
	length=0;
}//Ĭ�Ϲ��캯�� 

String::String(const char *c)
{
	int len=0;
	while(c[len++]);
	len--;
	s=new char[len+1];
	for(int i=0;i<=len;i++)
		s[i]=c[i];
	length=len;
}//���ع��캯����char�ַ������� 

String::String(const String &str)
{
	int len=str.length;
	s=new char[len+1];
	for(int i=0;i<=len;i++)
		s[i]=str.s[i];
	length=len;
}//�������캯����String���� 

String String::Substr(int pos,int n)
{
	char *p=new char[n+1];
	if(!p) return String();
	if(pos+n>length) return String();
	for(int i=0,j=pos;i<n;i++,j++)
		p[i]=s[j];
	String s(p);
	s.length=n;
	delete []p;
	return s;
}//��ȡ�Ӵ� 

void String::Clear()
{
	length=0;
}//����ַ��� 

bool String::Insert(String str,int pos)
{
	if(pos<0||pos>length) return false;
	int len=str.Length();
	if(len==0) return true;
	char *p=new char[length+len+1];
	if(!p) return false;
	for(int i=0;i<length;i++)
		p[i]=s[i];
	for(int i=0;i<length+len-1-pos;i++)
		p[length+len-1-i]=p[length-1-i];
	for(int i=0;i<len;i++)
		p[pos+i]=str.s[i];
	s=p;
	length+=len;
	return true;
}//�����ַ� 

bool String::Delete(int pos,int n)
{
	if(pos<0||n<=0||pos+n>length) return false;
	for(int i=0;i<length-pos-n;i++)
		s[pos+i]=s[pos+n+i];
	length-=n;
	return true;
}//ɾ���ַ� 

int String::Length()
{
	return length;
}//��ȡ���ĳ��� 

void String::Print()
{
	if(length==0)
	{
		cout<<"�ַ���Ϊ�մ�"<<endl;
		return;
	}
	for(int i=0;i<length;i++)
		cout<<s[i];
	cout<<endl;
}//��ӡ�ַ��� 


String& String::operator +=(String str)
{
	int newlen=length+str.Length();
	char *p=new char[newlen+1];
	if(!p) return *this;
	for(int i=0;i<length;i++)
		p[i]=s[i];
	for(int i=0;i<str.Length();i++)
		p[length+i]=str.s[i];
	s=p;
	length=newlen;
}//�����������+=����ʵ���ַ�����ƴ�� 

ostream & operator << (ostream &out,String &str)
{
	if(str.Length()==0)
		cout<<"�ַ���Ϊ�մ�"<<endl;
	else
	{
		for(int i=0;i<str.Length();i++)
			cout<<str.s[i];
		cout<<endl;
	}
	return out;
}//�����������<<����ʵ����cout��ӡ�ַ��� 



int nxt[10005];//KMP�㷨next���� 
void getnext(String pat)
{
	int i=0,j=-1;
	int len=pat.Length();//�ȼ�¼�����Խ�ʡʱ�� 
	nxt[0]=-1;
	while(i<len)
	{
		if(j==-1||pat.s[i]==pat.s[j])
			nxt[++i]=++j;
		else
			j=nxt[j];
	}
	return;
}//KMP�㷨getnext���� 

int kmp(String str,String pat)
{
	int i=0,j=0,len1=str.Length(),len2=pat.Length();
	while(i<len1)
	{
		if(j==-1||str.s[i]==pat.s[j])
			i++,j++;
		else
			j=nxt[j];
		if(j==len2)
			return i-len2;//���ҵ�������λ�ã�ע���ǵ�һ����ĸ��λ�� 
	}
	return -1;//δ�ҵ�����-1 
}//KMP�㷨���ĺ��� 

int String::Find(String pat,int pos)
{
	getnext(pat);
	int temp=kmp(Substr(pos,length-pos),pat);
	if(temp>=0)
		return pos+temp;//���ҵ��������Ӵ�������ԭ���е�λ�� 
	else if(temp==-1)
		return -1;//δ�ҵ�����-1 
}//���ַ����д�λ��pos��ʼѰ���Ӵ�str������λ�ã���δ�ҵ�����-1 



int main()
{
	//���ݲ��� 
	char a[]="abcdefg";
	String s(a);//��ֵ 
	String ss=s;//��ֵ 
	s=ss.Substr(2,3);//��ȡ�Ӵ� 
	cout<<"�ַ���s����Ϊ��"<<s.Length()<<endl;
	s.Print();
	s+=ss;//β��ƴ�� 
	cout<<"�ַ���s����Ϊ��"<<s.Length()<<endl;
	s.Print();
	String t("xyz");//��ֵ 
	s.Insert(t,0);//�����ַ� 
	cout<<"�ַ���s����Ϊ��"<<s.Length()<<endl;
	s.Print();
	s.Delete(3,3);//ɾ���ַ� 
	cout<<"�ַ���s����Ϊ��"<<s.Length()<<endl;
	s.Print();
	s+="aaa";//β��ƴ�� 
	cout<<"�ַ���s����Ϊ��"<<s.Length()<<endl;
	s.Print();
	s.Delete(3,7);//ɾ���ַ� 
	cout<<"�ַ���s����Ϊ��"<<s.Length()<<endl;
	s.Print();
	s.Insert("bbb",3);//�����ַ� 
	cout<<"�ַ���s����Ϊ��"<<s.Length()<<endl;
	cout<<s;//ʹ��coutͬ�����Դ�ӡ�ַ��� 
	cout<<"�ҵ��Ӵ�λ�ã�"<<s.Find("bbaa",0)<<endl;//��λ��0�����Ӵ� 
	cout<<"�ҵ��Ӵ�λ�ã�"<<s.Find("bbaa",5)<<endl;//��λ��5�����Ӵ� 
	s.Clear();//����ַ��� 
	cout<<"�ַ���s����Ϊ��"<<s.Length()<<endl;
	cout<<s;
	return 0;
}
