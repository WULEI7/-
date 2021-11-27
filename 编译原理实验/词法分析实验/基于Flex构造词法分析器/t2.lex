%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	int line=1;
	int count=0;
	int atline[1005];
	int type[1005];
	char text[1005][30];
	int errorflag=0;
	int errorcount=0;
%}

DIGIT [0-9]
OINTEGER [0-9]{DIGIT}*
INTEGER ("+"|"-")?{OINTEGER}
DECIMAL	 {INTEGER}"."{OINTEGER}
LETTER [A-Za-z]
IDENTIFY ({LETTER}|_)({LETTER}|{DIGIT}|_)*
OPT "+"|"-"|"*"|"/"|"+="|"-="|"*="|"/="|">"|"<"|"="|">="|"<="|"=="|"++"|"--"
BRACKET "("|")"|"["|"]"|"{"|"}"|","|";"|"\""|"\'"
TYPE void|int|double|char|float
KEYWORD main|return|if|else|do|while|for|scanf|printf|sqrt|abs
TYPEIDENTIFY %{IDENTIFY}|&{IDENTIFY}
COMMENT \/\/(.)*|\/\*(.|\n)*\*\/
FLOAT ({INTEGER}|{DECIMAL})(e|E){INTEGER}
ERROR ({INTEGER}|{DECIMAL})(e|E)

%%

\n {line++;}
{COMMENT} {}
{BRACKET} {count++;atline[count]=line;strcpy(text[count],yytext);type[count]=0;}
{OPT} {count++;atline[count]=line;strcpy(text[count],yytext);type[count]=1;}
{KEYWORD} {count++;atline[count]=line;strcpy(text[count],yytext);type[count]=2;}
{TYPE} {count++;atline[count]=line;strcpy(text[count],yytext);type[count]=3;}
{TYPEIDENTIFY} {count++;atline[count]=line;strcpy(text[count],yytext);type[count]=4;}
{IDENTIFY} {count++;atline[count]=line;strcpy(text[count],yytext);type[count]=5;}
{INTEGER} {count++;atline[count]=line;strcpy(text[count],yytext);type[count]=6;}
{DECIMAL} {count++;atline[count]=line;strcpy(text[count],yytext);type[count]=7;}
{FLOAT} {count++;atline[count]=line;strcpy(text[count],yytext);type[count]=8;}
{ERROR} {count++;atline[count]=line;strcpy(text[count],yytext);errorcount=count;errorflag=1;}
. {}

%%

int main()
{
	yyin=fopen("test.txt","r");
	yylex();
	fclose(yyin);
	int n=1;
	if(errorflag==1)
	{
		printf("Error at Line %d: Illegal floating point number \"%s\".",atline[errorcount],text[errorcount]);
		return 0;
	}
	while(n<=count)
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
		printf("%s)\n",text[n]);
		n++;
	}
	return 0;
}
int yywrap()
{
	return 1;
}