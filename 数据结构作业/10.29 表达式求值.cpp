#include <iostream>
#include <cstdio>
#include <stack>
#include <string> 
using namespace std;

char priority(char a,char b)
{
	int i,j;
	switch(a)
	{
		case '+':i=0;break;
		case '-':i=1;break;
		case '*':i=2;break;
		case '/':i=3;break;
		case '(':i=4;break;
		case ')':i=5;break;
		case '#':i=6;break;
	}
	switch(b)
	{
		case '+':j=0;break;
		case '-':j=1;break;
		case '*':j=2;break;
		case '/':j=3;break;
		case '(':j=4;break;
		case ')':j=5;break;
		case '#':j=6;break;
	}
	char p[7][7]=
	{
		'>','>','<','<','<','>','>',
		'>','>','<','<','<','>','>',
		'>','>','>','>','<','>','>',
		'>','>','>','>','<','>','>',
		'<','<','<','<','<','=','0',
		'>','>','>','>','0','>','>',
		'<','<','<','<','<','0','='
	};
	return p[i][j];
}//������ȹ�ϵ�� 

int operate(int a,char t,int b)
{
	switch(t)
	{
		case '+':return a+b;
		case '-':return a-b;
		case '*':return a*b;
		case '/':return a/b;
	}
}//���Ԫ������ 

int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	stack<char> opt;
	stack<int> num;
	opt.push('#');
	string s;
	cin>>s;
	int len=s.length();
	for(int i=0;i<len;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
			num.push(s[i]-'0');//���������ջ 
		else
		{
			switch(priority(opt.top(),s[i]))
			{
				case '<'://ջ��Ԫ�����ȼ��� 
					opt.push(s[i]);
					break;
				case '='://�����Ż�ĩβ���� 
					opt.pop();
					break;
				case '>'://��ջ������������ջ 
					char t=opt.top();
					opt.pop();
					int b=num.top();
					num.pop();
					int a=num.top();
					num.pop();
					num.push(operate(a,t,b));
					i--;
					break;
			}
		}
	}
	cout<<num.top()<<endl;
	return 0;
}
