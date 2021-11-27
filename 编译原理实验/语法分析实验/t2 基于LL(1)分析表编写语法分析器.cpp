#include <iostream>
#include <cstdio>
#include <string>
#include <stack>
#include <map> 
using namespace std;
string s;
string matrix[10][10];//Ԥ�������LL(1)���� 
char Vn[]={'E','e','T','t','F'};//���ս����������e����E'��t����T' 
char Vt[]={'a','+','*','(',')','#'};//�ս����# 
map<char,int> mpVn;//���ս����Ӧ�±� 
map<char,int> mpVt;//�ս����#��Ӧ�±� 
stack<char> t;//����ջ 
int errorflag=0;//�﷨������ 
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
	matrix[4][0]="a";matrix[4][3]="(E)";//������ʽ�ķ���Ԥ������� 
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
		if(X=='#'&&a=='#')//ƥ��������﷨��ȷ 
			break;
		for(int i=0;i<5;i++)
		{
			if(X==Vt[i])//X���ս�� 
			{
				if(X==a)//�ս��ƥ�䣬����� 
				{
					t.pop();
					pos++;
					flag=1;
					break;
				}
				else//�ս����ƥ�䣬�﷨���� 
				{
					errorflag=1;
					flag=2;
					break;
				}
			}
		}
		if(flag==1) continue;
		if(flag==2) break;
		//X�Ƿ��ս�� 
		if(matrix[mpVn[X]][mpVt[a]]=="NULL")//M[X,a]���ǲ���ʽ���﷨���� 
		{
			errorflag=1;
			break;
		}
		//M[X,a]�ǲ���ʽ 
		t.pop();//������ǰջ������ 
		int len=matrix[mpVn[X]][mpVt[a]].length();
		for(int i=len-1;i>=0;i--)//������ʽ�Ҳ����Ű�������ջ 
			t.push(matrix[mpVn[X]][mpVt[a]][i]);
	}
	if(errorflag==0)
		cout<<"Syntax analysis is right"<<endl;
	else
		cout<<"Error on syntax analysis"<<endl;
	return 0;
}
