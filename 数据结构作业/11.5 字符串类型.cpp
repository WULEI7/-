#include <iostream>
#include <cstdio>
using namespace std;

class String
{
	public:
		String();//默认构造函数 
		String(const char *c);//重载构造函数，char字符串类型 
		String(const String &str);//拷贝构造函数，String类型 
		String Substr(int pos,int n);//获取子串 
		void Clear();//清空字符串 
		bool Insert(String str,int pos);//插入字符 
		bool Delete(int pos,int n);//删除字符 
		int Find(String pat,int pos);//在字符串中从位置pos开始寻找子串pat并返回位置，若未找到返回-1 
		friend void getnext(String pat);//友元函数：KMP算法getnext函数 
		friend int kmp(String str,String pat);//友元函数：KMP算法核心函数 
		int Length();//获取串的长度 
		void Print();//打印字符串 
		String& operator +=(String str);//重载运算符“+=”，实现字符串的拼接 
		friend ostream & operator << (ostream &out,String &str);//重载运算符“<<”，实现用cout打印字符串 
	private:
		char *s;
		int length;
};//String类的实现 


String::String()
{
	s=new char[1];
	length=0;
}//默认构造函数 

String::String(const char *c)
{
	int len=0;
	while(c[len++]);
	len--;
	s=new char[len+1];
	for(int i=0;i<=len;i++)
		s[i]=c[i];
	length=len;
}//重载构造函数，char字符串类型 

String::String(const String &str)
{
	int len=str.length;
	s=new char[len+1];
	for(int i=0;i<=len;i++)
		s[i]=str.s[i];
	length=len;
}//拷贝构造函数，String类型 

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
}//获取子串 

void String::Clear()
{
	length=0;
}//清空字符串 

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
}//插入字符 

bool String::Delete(int pos,int n)
{
	if(pos<0||n<=0||pos+n>length) return false;
	for(int i=0;i<length-pos-n;i++)
		s[pos+i]=s[pos+n+i];
	length-=n;
	return true;
}//删除字符 

int String::Length()
{
	return length;
}//获取串的长度 

void String::Print()
{
	if(length==0)
	{
		cout<<"字符串为空串"<<endl;
		return;
	}
	for(int i=0;i<length;i++)
		cout<<s[i];
	cout<<endl;
}//打印字符串 


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
}//重载运算符“+=”，实现字符串的拼接 

ostream & operator << (ostream &out,String &str)
{
	if(str.Length()==0)
		cout<<"字符串为空串"<<endl;
	else
	{
		for(int i=0;i<str.Length();i++)
			cout<<str.s[i];
		cout<<endl;
	}
	return out;
}//重载运算符“<<”，实现用cout打印字符串 



int nxt[10005];//KMP算法next数组 
void getnext(String pat)
{
	int i=0,j=-1;
	int len=pat.Length();//先记录长度以节省时间 
	nxt[0]=-1;
	while(i<len)
	{
		if(j==-1||pat.s[i]==pat.s[j])
			nxt[++i]=++j;
		else
			j=nxt[j];
	}
	return;
}//KMP算法getnext函数 

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
			return i-len2;//若找到，返回位置，注意是第一个字母的位置 
	}
	return -1;//未找到返回-1 
}//KMP算法核心函数 

int String::Find(String pat,int pos)
{
	getnext(pat);
	int temp=kmp(Substr(pos,length-pos),pat);
	if(temp>=0)
		return pos+temp;//若找到，返回子串在整个原串中的位置 
	else if(temp==-1)
		return -1;//未找到返回-1 
}//在字符串中从位置pos开始寻找子串str并返回位置，若未找到返回-1 



int main()
{
	//数据测试 
	char a[]="abcdefg";
	String s(a);//赋值 
	String ss=s;//赋值 
	s=ss.Substr(2,3);//获取子串 
	cout<<"字符串s长度为："<<s.Length()<<endl;
	s.Print();
	s+=ss;//尾部拼接 
	cout<<"字符串s长度为："<<s.Length()<<endl;
	s.Print();
	String t("xyz");//赋值 
	s.Insert(t,0);//插入字符 
	cout<<"字符串s长度为："<<s.Length()<<endl;
	s.Print();
	s.Delete(3,3);//删除字符 
	cout<<"字符串s长度为："<<s.Length()<<endl;
	s.Print();
	s+="aaa";//尾部拼接 
	cout<<"字符串s长度为："<<s.Length()<<endl;
	s.Print();
	s.Delete(3,7);//删除字符 
	cout<<"字符串s长度为："<<s.Length()<<endl;
	s.Print();
	s.Insert("bbb",3);//插入字符 
	cout<<"字符串s长度为："<<s.Length()<<endl;
	cout<<s;//使用cout同样可以打印字符串 
	cout<<"找到子串位置："<<s.Find("bbaa",0)<<endl;//从位置0查找子串 
	cout<<"找到子串位置："<<s.Find("bbaa",5)<<endl;//从位置5查找子串 
	s.Clear();//清空字符串 
	cout<<"字符串s长度为："<<s.Length()<<endl;
	cout<<s;
	return 0;
}
