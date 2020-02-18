#include <stdio.h>
#include <math.h>

int main()
{
	int i,j,m,n,sign;
	char s[100],res[100];

	gets(s);

	sign=1;
	i=j=0;
	if(s[i]=='-')
	{
		sign=-1;
		i++;
	}
	else if(s[i]=='+')
		i++;

	res[j]=s[i];
	i+=2;
	j++;

	while(s[i]!='e'&&s[i]!='E')
		res[j++]=s[i++];
	res[j]='\0';

	i++;
	m=1;
	n=0;
	if(s[i]=='-')
	{
		m=-1;
		i++;
	}
	else if(s[i]=='+')
		i++;

	while(s[i]!='\0')
		n=n*10+s[i++]-'0';

	n*=m;

	if(sign==-1)
		printf("-");

	if(n<=-1)
	{
		printf("0.");
		n++;
		while(n<0)
		{
			printf("0");
			n++;
		}
		printf("%s",res);
	}
	else 
	{
		i=0;
		while(i<j&&n>=0)
		{
			printf("%c",res[i]);
			i++;
			n--;
		}
		if(i<j)
		{
			printf(".");
			while(i<j)
				printf("%c",res[i++]);
		}

		while(n>=0)
		{
			printf("0");
			n--;
		}
	}
	

	return 0;
}
