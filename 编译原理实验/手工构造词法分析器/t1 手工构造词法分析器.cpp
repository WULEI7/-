#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <sstream>
using namespace std;
string TYPE[5]={"void","int","double","char","float"};//type���� 
string KEYWORD[11]={"main","return","if","else","do","while","for","scanf","printf","sqrt","abs"};//keyword���� 
int line=1;//��ǰ�� 
int count=0;//���ʼ��� 
int atline[1005];//�浥�������� 
int type[1005];//�浥������ 
string text[1005];//�浥������ 
int errorflag=0;//������ 
int errorcount=0;//����ĵ���λ�� 
int numwithsign=0;//����������� 
int istypeident=0;//typeidentify��� 
int isincomment=0;//ע�ͱ�� 
string ss;//�浱ǰ�е��ַ��� 
bool isLetter(char x)//�ж��ַ��Ƿ�Ϊ��ĸ 
{
	if((x>='A'&&x<='Z')||(x>='a'&&x<='z'))
		return true;
	return false;
}
bool isDigit(char x)//�ж��ַ��Ƿ�Ϊ���� 
{
	if(x>='0'&&x<='9')
		return true;
	return false;
}
bool isOpt(char x)//�ж��ַ��Ƿ�Ϊ����� 
{
	char c[10]={'+','-','*','/','>','<','=','%','|','&'};
	for(int i=0;i<10;i++)
		if(x==c[i])
			return true;
	return false;
}

void scanLine(string s)//��һ�н��д��� 
{
	//ȥ�����׺���β�Ŀ��ַ� 
	//while(s[0]==' '||s[0]=='\t')
	//	s.erase(0,1);
	//while(s[s.length()-1]==' '||s[s.length()-1]=='\t')
	//	s.erase(s.length()-1,1);
	//cout<<s.length()<<endl;
	//cout<<s<<endl;
	int pos=0,len=s.length();//pos��¼��ǰλ�ã�lenΪ��ǰһ�е��ܳ��� 
	if(isincomment==1)//��ǰ���ڶ���ע�͵��� 
	{
		for(int i=0;i<len-1;i++)//Ѱ�Ҷ���ע�ͽ������ 
		{
			if(s.substr(i,2)=="*/")
			{
				isincomment=0;//��������ע�ͣ��Ը��м�������� 
				pos=i+2;
				break;
			}
		}
		return;//��ǰ��û�ж���ע�ͽ�����ǣ���������ֱ�ӽ�����һ�� 
	}
	while(pos<len)//�����׵���β��ȡ 
	{
		if(s[pos]==' '||s[pos]=='\t')//���˵��ո���Ʊ�� 
		{
			//pos++;
			s.erase(pos,1);
			len--;
			//�������Ա��ں��洦��ʱ����ǰһ����Ч�ַ� 
			continue;
		}
		else if(s[pos]=='('||s[pos]==')'||s[pos]=='['||s[pos]==']'||s[pos]=='{'||s[pos]=='}'
		||s[pos]==','||s[pos]==';'||s[pos]=='\"'||s[pos]=='\'')//ʶ����bracket 
		{
			count++;
			atline[count]=line;
			text[count]=s[pos];
			type[count]=0;
			pos++;
			continue;
		}
		//�������ͷ��ʶ��OPT������һЩ�����������ע�ͣ� 
		else if(s[pos]=='+')
		{
			if(pos==0||isOpt(s[pos-1]))//�á�+��������ǰ������ţ��ж��Ƿ�Ϊinteger��decimal��float 
			{
				numwithsign=1;
				goto label;
			}
			else if(s[pos+1]=='=')//��+=�� 
			{
				count++;
				atline[count]=line;
				text[count]="+=";
				type[count]=1;
				pos+=2;
				continue;
			}
			else//��+�� 
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
			if(pos==0||isOpt(s[pos-1]))//�á�-��������ǰ��ĸ��ţ��ж��Ƿ�Ϊinteger��decimal��float 
			{
				numwithsign=1;
				goto label;
			}
			else if(s[pos+1]=='-')//��-=�� 
			{
				count++;
				atline[count]=line;
				text[count]="-=";
				type[count]=1;
				pos+=2;
				continue;
			}
			else//��-�� 
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
			if(s[pos+1]=='=')//��*=�� 
			{
				count++;
				atline[count]=line;
				text[count]="*=";
				type[count]=1;
				pos+=2;
				continue;
			}
			else//��*�� 
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
			if(s[pos+1]=='/')//����ע�ͣ�ֱ�ӹ��˵���ǰ�к������� 
			{
				return;//ע����ֱ���˳������������˳�ѭ�� 
			}
			else if(s[pos+1]=='*')//����ע�ͣ���Ҫ����/*���͡�*/��֮����������ݶ����˵����п��ܻ���� 
			{
				isincomment=1; 
				for(int i=pos+2;i<len-1;i++)//�ڵ�ǰ��Ѱ�Ҷ���ע�ͽ�����ǡ�*/�� 
				{
					if(s.substr(i,2)=="*/")
					{
						isincomment=0;//��������ע�ͣ��Ը��м�������� 
						pos=i+2;
						continue;
					}
				}
				//��ǰ�в����ж���ע�ͽ������ 
				return;//ע����ֱ���˳������������˳�ѭ�� 
			}
			else if(s[pos+1]=='=')//��/=�� 
			{
				count++;
				atline[count]=line;
				text[count]="/=";
				type[count]=1;
				pos+=2;
				continue;
			}
			else//��/�� 
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
			if(s[pos+1]=='=')//��>=�� 
			{
				count++;
				atline[count]=line;
				text[count]=">=";
				type[count]=1;
				pos+=2;
				continue;
			}
			else//��>�� 
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
			if(s[pos+1]=='=')//��<=�� 
			{
				count++;
				atline[count]=line;
				text[count]="<=";
				type[count]=1;
				pos+=2;
				continue;
			}
			else//��<�� 
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
			if(s[pos+1]=='=')//��==�� 
			{
				count++;
				atline[count]=line;
				text[count]="==";
				type[count]=1;
				pos+=2;
				continue;
			}
			else//��=�� 
			{
				count++;
				atline[count]=line;
				text[count]="=";
				type[count]=1;
				pos++;
				continue;
			}
		}
		else if(s[pos]=='%')//����%��%=���㣬��typeidentify����� 
		{
			if(isLetter(s[pos+1]))//typeidentify
			{
				istypeident=1;
				goto label2;
			}
			else if(s[pos+1]=='=')//��%=�� 
			{
				count++;
				atline[count]=line;
				text[count]="%=";
				type[count]=1;
				pos+=2;
				continue;
			}
			else//��%�� 
			{
				count++;
				atline[count]=line;
				text[count]="%";
				type[count]=1;
				pos++;
				continue;
			}
		}
		else if(s[pos]=='&')//����&��&&���㣬��typeidentify����� 
		{
			if(isLetter(s[pos+1]))//typeidentify
			{
				istypeident=1;
				goto label2;
			}
			else if(s[pos+1]=='&')//��&&�� 
			{
				count++;
				atline[count]=line;
				text[count]="&&";
				type[count]=1;
				pos+=2;
				continue;
			}
			else//��&�� 
			{
				count++;
				atline[count]=line;
				text[count]="&";
				type[count]=1;
				pos++;
				continue;
			}
		}
		else if(s[pos]=='|')//����|��||����
		{
			if(s[pos+1]=='|')//��||�� 
			{
				count++;
				atline[count]=line;
				text[count]="||";
				type[count]=1;
				pos+=2;
				continue;
			}
			else//��|�� 
			{
				count++;
				atline[count]=line;
				text[count]="|";
				type[count]=1;
				pos++;
				continue;
			}
		}
		else if(isLetter(s[pos]))//��ĸ��ͷ��ʶ��keyword��type��identify 
		{
			if(istypeident==0)
			{
				int endflag=0;
				for(int i=0;i<11;i++)
				{
					if(s.substr(pos,KEYWORD[i].length())==KEYWORD[i]&&!isLetter(s[pos+KEYWORD[i].length()])&&!isDigit(s[pos+KEYWORD[i].length()])
					&&s[pos+KEYWORD[i].length()]!='_')//��keyword 
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
					&&s[pos+TYPE[i].length()]!='_')//��type 
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
			label2://typeidentify���ж���� 
			int start=pos,length=0;
			if(istypeident==1)//��typeidentify 
			{
				pos++;
				length++;
			}
			while(isLetter(s[pos])||isDigit(s[pos])||s[pos]=='_')
			{
				length++;
				pos++;
			}//��identify 
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
		else if(s[pos]=='_')//�»��߿�ͷ 
		{
			int start=pos,length=0;
			while(isLetter(s[pos])||isDigit(s[pos])||s[pos]=='_')
			{
				length++;
				pos++;
			}//��identify 
			count++;
			atline[count]=line;
			type[count]=5;
			text[count]=s.substr(start,length);
			continue;
		}
		else if(isDigit(s[pos]))//���ֿ�ͷ 
		{
			numwithsign=0;
			label://�����������ж���� 
			int start=pos,length=0;
			if(numwithsign==1)//����Ǵ������������Ϸ��� 
			{
				pos++;
				length++;
			}
			while(isDigit(s[pos]))
			{
				length++;
				pos++;
			}
			if(s[pos]=='.')//decimal��float 
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
	}//�����׵���β��ȡ 
	
}

int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	//freopen("test.txt","r",stdin);//ע���ύ��ʱ��Ҫע�͵� 
	while(getline(cin,ss))//���ж�ȡ 
	{
		scanLine(ss);//�Ը��н��д��� 
		line++;//���У�������1 
	}
	int n=1;
	if(errorflag==1)//���� 
	{
		printf("Error at Line %d: Illegal floating point number \"%s\".",atline[errorcount],text[errorcount].c_str());
		return 0;
	}
	while(n<=count)//û�б����������ÿ���� 
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
