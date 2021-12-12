#include <iostream>
#include <cstdio>
#include <string>
#include <stack>
#include <map>
using namespace std;
string s;//输入句子的字符串 
int errorflag=0;//报错标记 
char Vt[7]={'i','+','(',')','[',']','#'};//终结符和# 
char Vn[2]={'E','T'};//非终结符 
map<char,int> mpVt;//终结符和#对应下标 
map<char,int> mpVn;//非终结符对应下标 
int ACTION[12][7]//ACTION表：正数表示S（移入），负数表示r（归约），100表示接受acc，0表示报错 
={
	4,0,3,0,0,0,0,
	0,5,0,0,0,0,100,
	0,-2,0,-2,0,-2,-2,
	4,0,3,0,0,0,0,
	0,-4,0,-4,7,-4,-4,
	4,0,3,0,0,0,0,
	0,5,0,9,0,0,0,
	4,0,3,0,0,0,0,
	0,-1,0,-1,0,-1,-1,
	0,-3,0,-3,0,-3,-3,
	0,5,0,0,0,11,0,
	0,-5,0,-5,0,-5,-5
};
int GOTO[12][2]//GOTO表 
={
	1,2,
	0,0,
	0,0,
	6,2,
	0,0,
	0,8,
	0,0,
	10,2,
	0,0,
	0,0,
	0,0,
	0,0,		
};
stack<int> status;//状态栈 
stack<char> symbol;//符号栈 
void Analysis()//LR语法分析 
{
	int pos=0;//输入串当前位置 
	status.push(0);//将状态0加入状态栈 
	while(1)
	{
		int st=status.top();//当前状态 
		char x=s[pos];//当前输入串字符 
		int t=ACTION[st][mpVt[x]];//ACTION值 
		if(t==100)//接受acc，分析成功 
			return;
		else if(t>0)//移入 
		{
			status.push(t);
			symbol.push(x);
			pos++;
		}
		else if(t<0)//归约 
		{
			if(t==-1)//E->E+T归约 
			{
				for(int i=0;i<3;i++)
					status.pop();
				for(int i=0;i<3;i++)
					symbol.pop();
				symbol.push('E');
			}
			if(t==-2)//E->T归约 
			{
				status.pop();
				symbol.pop();
				symbol.push('E');
			}
			if(t==-3)//T->(E)归约 
			{
				for(int i=0;i<3;i++)
					status.pop();
				for(int i=0;i<3;i++)
					symbol.pop();
				symbol.push('T');
			}
			if(t==-4)//T->id归约 
			{
				status.pop();
				symbol.pop();
				symbol.push('T'); 
			}
			if(t==-5)//T->id[E]归约 
			{
			    for(int i=0;i<4;i++)
					status.pop();
				for(int i=0;i<4;i++)
					symbol.pop();
				symbol.push('T');
			}
			if(GOTO[status.top()][mpVn[symbol.top()]]>0)//GOTO值 
		        status.push(GOTO[status.top()][mpVn[symbol.top()]]);
		    else//GOTO报错 
		   	{
		   		errorflag=1;
		   		return;
			}
		}
		else//ACTION报错 
		{
			errorflag=1;
			return;
		}
	}
	return;
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	for(int i=0;i<7;i++)
		mpVt[Vt[i]]=i;
	for(int i=0;i<2;i++)
		mpVn[Vn[i]]=i;
	getline(cin,s);//输入一行句子 
	for(unsigned int i=0;i<s.length();i++)
	{
		if(s[i]==' ')
		{
			s.erase(i,1);
			i--;
		}
	}//删除句子中的空格 
	for(unsigned int i=0;i<s.length();i++)
	{
		if(s[i]=='a')
		{
			s.replace(i,2,"i");
			i--;
		}
	}//将变量名替换为i 
	//cout<<s<<endl;
	s+="#";//在句子末尾加上# 
	Analysis();//LR语法分析 
	if(errorflag==0)
		cout<<"Syntax analysis is right"<<endl;
	else
		cout<<"Error on syntax analysis"<<endl;
	return 0; 
}
