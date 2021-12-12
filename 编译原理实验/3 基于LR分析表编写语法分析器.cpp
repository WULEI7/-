#include <iostream>
#include <cstdio>
#include <string>
#include <stack>
#include <map>
using namespace std;
string s;//������ӵ��ַ��� 
int errorflag=0;//������ 
char Vt[7]={'i','+','(',')','[',']','#'};//�ս����# 
char Vn[2]={'E','T'};//���ս�� 
map<char,int> mpVt;//�ս����#��Ӧ�±� 
map<char,int> mpVn;//���ս����Ӧ�±� 
int ACTION[12][7]//ACTION��������ʾS�����룩��������ʾr����Լ����100��ʾ����acc��0��ʾ���� 
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
int GOTO[12][2]//GOTO�� 
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
stack<int> status;//״̬ջ 
stack<char> symbol;//����ջ 
void Analysis()//LR�﷨���� 
{
	int pos=0;//���봮��ǰλ�� 
	status.push(0);//��״̬0����״̬ջ 
	while(1)
	{
		int st=status.top();//��ǰ״̬ 
		char x=s[pos];//��ǰ���봮�ַ� 
		int t=ACTION[st][mpVt[x]];//ACTIONֵ 
		if(t==100)//����acc�������ɹ� 
			return;
		else if(t>0)//���� 
		{
			status.push(t);
			symbol.push(x);
			pos++;
		}
		else if(t<0)//��Լ 
		{
			if(t==-1)//E->E+T��Լ 
			{
				for(int i=0;i<3;i++)
					status.pop();
				for(int i=0;i<3;i++)
					symbol.pop();
				symbol.push('E');
			}
			if(t==-2)//E->T��Լ 
			{
				status.pop();
				symbol.pop();
				symbol.push('E');
			}
			if(t==-3)//T->(E)��Լ 
			{
				for(int i=0;i<3;i++)
					status.pop();
				for(int i=0;i<3;i++)
					symbol.pop();
				symbol.push('T');
			}
			if(t==-4)//T->id��Լ 
			{
				status.pop();
				symbol.pop();
				symbol.push('T'); 
			}
			if(t==-5)//T->id[E]��Լ 
			{
			    for(int i=0;i<4;i++)
					status.pop();
				for(int i=0;i<4;i++)
					symbol.pop();
				symbol.push('T');
			}
			if(GOTO[status.top()][mpVn[symbol.top()]]>0)//GOTOֵ 
		        status.push(GOTO[status.top()][mpVn[symbol.top()]]);
		    else//GOTO���� 
		   	{
		   		errorflag=1;
		   		return;
			}
		}
		else//ACTION���� 
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
	getline(cin,s);//����һ�о��� 
	for(unsigned int i=0;i<s.length();i++)
	{
		if(s[i]==' ')
		{
			s.erase(i,1);
			i--;
		}
	}//ɾ�������еĿո� 
	for(unsigned int i=0;i<s.length();i++)
	{
		if(s[i]=='a')
		{
			s.replace(i,2,"i");
			i--;
		}
	}//���������滻Ϊi 
	//cout<<s<<endl;
	s+="#";//�ھ���ĩβ����# 
	Analysis();//LR�﷨���� 
	if(errorflag==0)
		cout<<"Syntax analysis is right"<<endl;
	else
		cout<<"Error on syntax analysis"<<endl;
	return 0; 
}
