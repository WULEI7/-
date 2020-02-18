#include <stdio.h>
#include <string.h>
#define LENGTH  100
void reverse(char s[])
{
	int i,j,c;;
	for(i=0,j=strlen(s)-1; i<j; i++,j--){
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}
int subLInt(char s1[], char s2[]);
int main()
{
    char intstr1[LENGTH],intstr2[LENGTH];
	int IfNum=0,i,j,a,n;
    
	scanf("%d%d",&a,&n);

	for(i=0;i<n;i++)
		intstr1[i]='0'+a;
	intstr1[i]='\0';

	for(i=n-1;i>=1;i--)
	{
		for(j=0;j<i;j++)
			intstr2[j]='0'+a;
		intstr2[j]='\0';
		subLInt(intstr1,intstr2);
	}

	IfNum=0;
    for(i=0;intstr1[i]!='\0';i++)
		if(IfNum)
			printf("%c",intstr1[i]);
		else if(intstr1[i]!='0')
		{
			printf("%c",intstr1[i]);
			IfNum=1;
		}
	printf("\n");
    return 0;
}

int subLInt(char s1[], char s2[])
{
	int tmp,c=0,sign=1,i;
	char s[LENGTH];
	if(strlen(s1) < strlen(s2)){
		strcpy(s, s1);
		strcpy(s1,s2);
		strcpy(s2,s);
		sign=-1;
	}
	else if(strlen(s1) > strlen(s2))
		sign=1;
	else
	{
		if(strcmp(s1,s2)<0)
		{
			strcpy(s, s1);
			strcpy(s1,s2);
			strcpy(s2,s);
			sign=-1;
		}
		else if(strcmp(s1,s2)==0)
			return 0;
		else
			sign=1;
	}

	reverse(s1); reverse(s2);
	i=0;
	while(s2[i] != '\0'){
		tmp = (s1[i]-'0') - (s2[i]-'0') - c;
		if(tmp<0)
		{
			c=1;
			s1[i]=10+tmp+'0';
		}
		else
		{
			c=0;
			s1[i]=tmp+'0';
		}
		i++;
	}
	while(s1[i] != '\0' && c){
		tmp = s1[i]-'0' - c;
		if(tmp<0)
		{
			c=1;
			s1[i]=10+tmp+'0';
		}
		else
		{
			c=0;
			s1[i]=tmp+'0';
		}
		i++;
	}
	reverse(s1);
	return sign;
}

/*

5 5
49385

5 20
49382716049382716060

1.
1 1
1

2.

6 9
592592598

3.

6 19
5925925925925925938

4.

9 80
88888888888888888888888888888888888888888888888888888888888888888888888888888968


5.

7 77
69135802469135802469135802469135802469135802469135802469135802469135802469195


*/

