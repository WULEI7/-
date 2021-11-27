#include <iostream>
#include <cstdio>
#include <string>
#include <stack>
#include <map> 
using namespace std;
string s;
string matrix[10][10];//预测分析表（LL(1)矩阵） 
char Vn[]={'E','e','T','t','F'};//非终结符，这里用e代表E'，t代表T' 
char Vt[]={'a','+','*','(',')','#'};//终结符和# 
map<char,int> mpVn;//非终结符对应下标 
map<char,int> mpVt;//终结符和#对应下标 
stack<char> t;//分析栈 
int errorflag=0;//语法错误标记 
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	for(int i=0;i<5;i++)
		mpVn[Vn[i]]=i;
	for(int i=0;i<6;i++)
		mpVt[Vt[i]]=i;
	for(int i=0;i<5;i++)
	for(int j=0;j<6;j++)
		matrix[i][j]="NULL";
	matrix[0][0]="Te";matrix[0][3]="Te";
	matrix[1][1]="+Te";matrix[1][4]="";matrix[1][5]="";
	matrix[2][0]="Ft";matrix[2][3]="Ft";
	matrix[3][1]="";matrix[3][2]="*Ft";matrix[3][4]="";matrix[3][5]="";
	matrix[4][0]="a";matrix[4][3]="(E)";//构造表达式文法的预测分析表 
	cin>>s;
	s+="#";
	int pos=0;
	t.push('#');
	t.push('E');
	while(1)
	{
		char X=t.top();
		char a=s[pos];
		int flag=0;
		if(X=='#'&&a=='#')//匹配结束，语法正确 
			break;
		for(int i=0;i<5;i++)
		{
			if(X==Vt[i])//X是终结符 
			{
				if(X==a)//终结符匹配，向后处理 
				{
					t.pop();
					pos++;
					flag=1;
					break;
				}
				else//终结符不匹配，语法错误 
				{
					errorflag=1;
					flag=2;
					break;
				}
			}
		}
		if(flag==1) continue;
		if(flag==2) break;
		//X是非终结符 
		if(matrix[mpVn[X]][mpVt[a]]=="NULL")//M[X,a]不是产生式，语法错误 
		{
			errorflag=1;
			break;
		}
		//M[X,a]是产生式 
		t.pop();//弹出当前栈顶符号 
		int len=matrix[mpVn[X]][mpVt[a]].length();
		for(int i=len-1;i>=0;i--)//将产生式右部符号按逆序入栈 
			t.push(matrix[mpVn[X]][mpVt[a]][i]);
	}
	if(errorflag==0)
		cout<<"Syntax analysis is right"<<endl;
	else
		cout<<"Error on syntax analysis"<<endl;
	return 0;
}
