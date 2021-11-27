#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <sstream>
using namespace std;
string TYPE[5]={"void","int","double","char","float"};//type类型 
string KEYWORD[11]={"main","return","if","else","do","while","for","scanf","printf","sqrt","abs"};//keyword类型 
int line=1;//当前行 
int count=0;//单词计数 
int atline[1005];//存单词所在行 
int type[1005];//存单词类型 
string text[1005];//存单词内容 
int errorflag=0;//报错标记 
int errorcount=0;//报错的单词位置 
int numwithsign=0;//带符号数标记 
int istypeident=0;//typeidentify标记 
int isincomment=0;//注释标记 
string ss;//存当前行的字符串 
bool isLetter(char x)//判断字符是否为字母 
{
	if((x>='A'&&x<='Z')||(x>='a'&&x<='z'))
		return true;
	return false;
}
bool isDigit(char x)//判断字符是否为数字 
{
	if(x>='0'&&x<='9')
		return true;
	return false;
}
bool isOpt(char x)//判断字符是否为运算符 
{
	char c[10]={'+','-','*','/','>','<','=','%','|','&'};
	for(int i=0;i<10;i++)
		if(x==c[i])
			return true;
	return false;
}

void scanLine(string s)//对一行进行处理 
{
	//去掉行首和行尾的空字符 
	//while(s[0]==' '||s[0]=='\t')
	//	s.erase(0,1);
	//while(s[s.length()-1]==' '||s[s.length()-1]=='\t')
	//	s.erase(s.length()-1,1);
	//cout<<s.length()<<endl;
	//cout<<s<<endl;
	int pos=0,len=s.length();//pos记录当前位置，len为当前一行的总长度 
	if(isincomment==1)//当前行在多行注释当中 
	{
		for(int i=0;i<len-1;i++)//寻找多行注释结束标记 
		{
			if(s.substr(i,2)=="*/")
			{
				isincomment=0;//结束多行注释，对该行继续向后处理 
				pos=i+2;
				break;
			}
		}
		return;//当前行没有多行注释结束标记，不作处理，直接进入下一行 
	}
	while(pos<len)//从行首到行尾读取 
	{
		if(s[pos]==' '||s[pos]=='\t')//过滤掉空格和制表符 
		{
			//pos++;
			s.erase(pos,1);
			len--;
			//这样可以便于后面处理时考虑前一个有效字符 
			continue;
		}
		else if(s[pos]=='('||s[pos]==')'||s[pos]=='['||s[pos]==']'||s[pos]=='{'||s[pos]=='}'
		||s[pos]==','||s[pos]==';'||s[pos]=='\"'||s[pos]=='\'')//识别界符bracket 
		{
			count++;
			atline[count]=line;
			text[count]=s[pos];
			type[count]=0;
			pos++;
			continue;
		}
		//运算符开头，识别OPT，或者一些特殊情况（见注释） 
		else if(s[pos]=='+')
		{
			if(pos==0||isOpt(s[pos-1]))//该“+”是正数前面的正号，判断是否为integer、decimal、float 
			{
				numwithsign=1;
				goto label;
			}
			else if(s[pos+1]=='=')//“+=” 
			{
				count++;
				atline[count]=line;
				text[count]="+=";
				type[count]=1;
				pos+=2;
				continue;
			}
			else//“+” 
			{
				count++;
				atline[count]=line;
				text[count]="+";
				type[count]=1;
				pos++;
				continue;
			}
		}
		else if(s[pos]=='-')
		{
			if(pos==0||isOpt(s[pos-1]))//该“-”是正数前面的负号，判断是否为integer、decimal、float 
			{
				numwithsign=1;
				goto label;
			}
			else if(s[pos+1]=='-')//“-=” 
			{
				count++;
				atline[count]=line;
				text[count]="-=";
				type[count]=1;
				pos+=2;
				continue;
			}
			else//“-” 
			{
				count++;
				atline[count]=line;
				text[count]="-";
				type[count]=1;
				pos++;
				continue;
			}
		}
		else if(s[pos]=='*')
		{
			if(s[pos+1]=='=')//“*=” 
			{
				count++;
				atline[count]=line;
				text[count]="*=";
				type[count]=1;
				pos+=2;
				continue;
			}
			else//“*” 
			{
				count++;
				atline[count]=line;
				text[count]="*";
				type[count]=1;
				pos++;
				continue;
			}
		}
		else if(s[pos]=='/')
		{
			if(s[pos+1]=='/')//单行注释，直接过滤掉当前行后面内容 
			{
				return;//注意是直接退出函数，不是退出循环 
			}
			else if(s[pos+1]=='*')//多行注释，需要将“/*”和“*/”之间的所有内容都过滤掉，有可能会跨行 
			{
				isincomment=1; 
				for(int i=pos+2;i<len-1;i++)//在当前行寻找多行注释结束标记“*/” 
				{
					if(s.substr(i,2)=="*/")
					{
						isincomment=0;//结束多行注释，对该行继续向后处理 
						pos=i+2;
						continue;
					}
				}
				//当前行不含有多行注释结束标记 
				return;//注意是直接退出函数，不是退出循环 
			}
			else if(s[pos+1]=='=')//“/=” 
			{
				count++;
				atline[count]=line;
				text[count]="/=";
				type[count]=1;
				pos+=2;
				continue;
			}
			else//“/” 
			{
				count++;
				atline[count]=line;
				text[count]="/";
				type[count]=1;
				pos++;
				continue;
			}
		}
		else if(s[pos]=='>')
		{
			if(s[pos+1]=='=')//“>=” 
			{
				count++;
				atline[count]=line;
				text[count]=">=";
				type[count]=1;
				pos+=2;
				continue;
			}
			else//“>” 
			{
				count++;
				atline[count]=line;
				text[count]=">";
				type[count]=1;
				pos++;
				continue;
			}
		}
		else if(s[pos]=='<')
		{
			if(s[pos+1]=='=')//“<=” 
			{
				count++;
				atline[count]=line;
				text[count]="<=";
				type[count]=1;
				pos+=2;
				continue;
			}
			else//“<” 
			{
				count++;
				atline[count]=line;
				text[count]="<";
				type[count]=1;
				pos++;
				continue;
			}
		}
		else if(s[pos]=='=')
		{
			if(s[pos+1]=='=')//“==” 
			{
				count++;
				atline[count]=line;
				text[count]="==";
				type[count]=1;
				pos+=2;
				continue;
			}
			else//“=” 
			{
				count++;
				atline[count]=line;
				text[count]="=";
				type[count]=1;
				pos++;
				continue;
			}
		}
		else if(s[pos]=='%')//包含%、%=运算，和typeidentify的情况 
		{
			if(isLetter(s[pos+1]))//typeidentify
			{
				istypeident=1;
				goto label2;
			}
			else if(s[pos+1]=='=')//“%=” 
			{
				count++;
				atline[count]=line;
				text[count]="%=";
				type[count]=1;
				pos+=2;
				continue;
			}
			else//“%” 
			{
				count++;
				atline[count]=line;
				text[count]="%";
				type[count]=1;
				pos++;
				continue;
			}
		}
		else if(s[pos]=='&')//包含&、&&运算，和typeidentify的情况 
		{
			if(isLetter(s[pos+1]))//typeidentify
			{
				istypeident=1;
				goto label2;
			}
			else if(s[pos+1]=='&')//“&&” 
			{
				count++;
				atline[count]=line;
				text[count]="&&";
				type[count]=1;
				pos+=2;
				continue;
			}
			else//“&” 
			{
				count++;
				atline[count]=line;
				text[count]="&";
				type[count]=1;
				pos++;
				continue;
			}
		}
		else if(s[pos]=='|')//包含|、||运算
		{
			if(s[pos+1]=='|')//“||” 
			{
				count++;
				atline[count]=line;
				text[count]="||";
				type[count]=1;
				pos+=2;
				continue;
			}
			else//“|” 
			{
				count++;
				atline[count]=line;
				text[count]="|";
				type[count]=1;
				pos++;
				continue;
			}
		}
		else if(isLetter(s[pos]))//字母开头，识别keyword、type、identify 
		{
			if(istypeident==0)
			{
				int endflag=0;
				for(int i=0;i<11;i++)
				{
					if(s.substr(pos,KEYWORD[i].length())==KEYWORD[i]&&!isLetter(s[pos+KEYWORD[i].length()])&&!isDigit(s[pos+KEYWORD[i].length()])
					&&s[pos+KEYWORD[i].length()]!='_')//是keyword 
					{
						count++;
						atline[count]=line;
						type[count]=2;
						text[count]=KEYWORD[i];
						pos+=KEYWORD[i].length();
						endflag=1;
						break;
					}
				}
				if(endflag==1) continue;
				for(int i=0;i<5;i++)
				{
					if(s.substr(pos,TYPE[i].length())==TYPE[i]&&!isLetter(s[pos+TYPE[i].length()])&&!isDigit(s[pos+TYPE[i].length()])
					&&s[pos+TYPE[i].length()]!='_')//是type 
					{
						count++;
						atline[count]=line;
						type[count]=3;
						text[count]=TYPE[i];
						pos+=TYPE[i].length();
						endflag=1;
						break;
					}
				}
				if(endflag==1) continue;
			}
			label2://typeidentify的判断入口 
			int start=pos,length=0;
			if(istypeident==1)//是typeidentify 
			{
				pos++;
				length++;
			}
			while(isLetter(s[pos])||isDigit(s[pos])||s[pos]=='_')
			{
				length++;
				pos++;
			}//是identify 
			count++;
			atline[count]=line;
			text[count]=s.substr(start,length);
			if(istypeident==1)//typeidentify 
			{
				type[count]=4;
				istypeident=0;
				continue; 
			}
			type[count]=5;
			continue;
		}
		else if(s[pos]=='_')//下划线开头 
		{
			int start=pos,length=0;
			while(isLetter(s[pos])||isDigit(s[pos])||s[pos]=='_')
			{
				length++;
				pos++;
			}//是identify 
			count++;
			atline[count]=line;
			type[count]=5;
			text[count]=s.substr(start,length);
			continue;
		}
		else if(isDigit(s[pos]))//数字开头 
		{
			numwithsign=0;
			label://带符号数的判断入口 
			int start=pos,length=0;
			if(numwithsign==1)//如果是带符号数，带上符号 
			{
				pos++;
				length++;
			}
			while(isDigit(s[pos]))
			{
				length++;
				pos++;
			}
			if(s[pos]=='.')//decimal或float 
			{
				pos++;
				int length2=length+1;
				while(isDigit(s[pos]))
				{
					length2++;
					pos++;
				}
				if(s[pos]=='e'||s[pos]=='E')
				{
					pos++;
					int length3=length2+1;
					if(s[pos]=='+'||s[pos]=='-')
					{
						pos++;
						length3++;
						while(isDigit(s[pos]))
						{
							length3++;
							pos++;
						}
						//float 
						count++;
						atline[count]=line;
						text[count]=s.substr(start,length3);
						type[count]=8;
						continue;
					}
					else if(pos==len||!isDigit(s[pos]))//error 
					{
						count++;
						atline[count]=line;
						text[count]=s.substr(start,length3);
						errorcount=count;
						errorflag=1;
						continue;
					}
					while(isDigit(s[pos]))
					{
						length3++;
						pos++;
					}
					//float 
					count++;
					atline[count]=line;
					text[count]=s.substr(start,length3);
					type[count]=8;
					continue;
				}
				//decimal 
				count++;
				atline[count]=line;
				text[count]=s.substr(start,length2);
				type[count]=7;
				continue;
			}
			else if(s[pos]=='e'||s[pos]=='E')
			{
				pos++;
				int length3=length+1;
				if(s[pos]=='+'||s[pos]=='-')
				{
					pos++;
					length3++;
					while(isDigit(s[pos]))
					{
						length3++;
						pos++;
					}
					//float 
					count++;
					atline[count]=line;
					text[count]=s.substr(start,length3);
					type[count]=8;
					continue;
				}
				else if(pos==len||!isDigit(s[pos]))//error 
				{
					count++;
					atline[count]=line;
					text[count]=s.substr(start,length3);
					errorcount=count;
					errorflag=1;
					continue;
				}
				while(isDigit(s[pos]))
				{
					length3++;
					pos++;
				}
				//float 
				count++;
				atline[count]=line;
				text[count]=s.substr(start,length3);
				type[count]=8;
				continue;
			}
			else//integer 
			{
				count++;
				atline[count]=line;
				text[count]=s.substr(start,length);
				type[count]=6;
				continue;
			}
		}
	}//从行首到行尾读取 
	
}

int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	//freopen("test.txt","r",stdin);//注意提交的时候要注释掉 
	while(getline(cin,ss))//按行读取 
	{
		scanLine(ss);//对该行进行处理 
		line++;//换行，行数加1 
	}
	int n=1;
	if(errorflag==1)//报错 
	{
		printf("Error at Line %d: Illegal floating point number \"%s\".",atline[errorcount],text[errorcount].c_str());
		return 0;
	}
	while(n<=count)//没有报错，依次输出每个词 
	{
		printf("line%d:(",atline[n]);
		if(type[n]==0) printf("bracket, ");
		else if(type[n]==1) printf("OPT, ");
		else if(type[n]==2) printf("keyword, ");
		else if(type[n]==3) printf("type, ");
		else if(type[n]==4) printf("typeidentify, ");
		else if(type[n]==5) printf("identify, ");
		else if(type[n]==6) printf("integer, ");
		else if(type[n]==7) printf("decimal, ");
		else if(type[n]==8) printf("float, ");
		printf("%s)\n",text[n].c_str());
		n++;
	}
	return 0;
}
