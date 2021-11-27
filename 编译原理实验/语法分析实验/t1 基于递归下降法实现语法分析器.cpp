#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int pos=0,len=0,errorflag=0;
string s;
void E();
void E1();
void T();
void T1();
void F();
void E()//E->TE'
{
	T();
	E1();
}
void E1()//E'->+TE'|e
{
	if(s[pos]=='+')
	{
		pos++;
		T();
		E1();
	}
}
void T()//T->FT'
{
	F();
	T1();
}
void T1()//T'->*FT'|e
{
	if(s[pos]=='*')
	{
		pos++;
		F();
		T1();
	}
}
void F()//a|(E)
{
	if(s[pos]=='a')
		pos++;
	else
	{
		if(s[pos]=='(')
		{
			pos++;
			E();
			if(s[pos]==')')
				pos++;
			else
				errorflag=1;
		}
		else
			errorflag=1;
	}
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	getline(cin,s); 
	len=s.length();
	E();//递归处理 
	if(errorflag==1||pos!=len)//存在语法错误，或未处理到句子末尾 
		cout<<"Error on syntax analysis"<<endl;
	else
		cout<<"Syntax analysis is right"<<endl;
	return 0;
}
