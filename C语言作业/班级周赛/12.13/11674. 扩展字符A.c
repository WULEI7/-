#include <stdio.h>
#define M 512
int main()
{
	int i=0,j=0;
	char s1[M],s2[M],ch;
	gets(s1);
	for(i=0;s1[i]!='\0';i++)
	{
		s2[j]=s1[i];
		j++;
		if(s1[i+1]=='-')
		{
			if(s1[i]>='a'&&s1[i]<='z')
			{
				if(s1[i+2]>='a'&&s1[i+2]<='z'&&s1[i]<s1[i+2]){
					for(ch=s1[i]+1;ch<s1[i+2];ch++)
						s2[j++]=ch;
						i++;
				}
					else ;
			}
			else if(s1[i]>='0'&&s1[i]<='9') 
			{
                if(s1[i+2]>='0'&&s1[i+2]<='9'&&s1[i]<s1[i+2]){
					for(ch=s1[i]+1;ch<s1[i+2];ch++)
						s2[j++]=ch;
						i++;
					}
					else ;
			}
			else if(s1[i]>='A'&&s1[i]<='Z') 
			{
                if(s1[i+2]>='A'&&s1[i+2]<='Z'&&s1[i]<s1[i+2]){
					for(ch=s1[i]+1;ch<s1[i+2];ch++)
						s2[j++]=ch;
						i++;
					}
					else ;
			}
		}
		else ;
	}
		s2[j]='\0';
		puts(s2);
}



