#include <cstdio>
int main()
{
	int n;
	char r[3],s[2],t[2];
	scanf("%d",&n);
	scanf("%s",s);
	scanf("%s",t);
	int flag=0,cons=0;
	if(s[0]==s[1]||t[0]==t[1])
	{
		cons=0;
		for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
		for(int k=0;k<3;k++)
		{
			r[0]='a'+i;
			r[1]='a'+j;
			r[2]='a'+k;
			if(r[0]==r[1]||r[0]==r[2]||r[1]==r[2])
				continue;
			if(r[0]==s[0]&&r[1]==s[1]||r[1]==s[0]&&r[2]==s[1]||r[2]==s[0]&&r[0]==s[1]
			 ||r[0]==t[0]&&r[1]==t[1]||r[1]==t[0]&&r[2]==t[1]||r[2]==t[0]&&r[0]==t[1])
				continue;
			flag=1;
			goto label;
		}
	}
	else
	{
		cons=1;
		for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
		for(int k=0;k<3;k++)
		{
			r[0]='a'+i;
			r[1]='a'+j;
			r[2]='a'+k;
			if(r[0]==r[1]||r[0]==r[2]||r[1]==r[2])
				continue;
			if(r[0]==s[0]&&r[1]==s[1]||r[1]==s[0]&&r[2]==s[1]
			 ||r[0]==t[0]&&r[1]==t[1]||r[1]==t[0]&&r[2]==t[1])
				continue;
			flag=1;
			goto label;
		}
	}
	label:
	if(flag==0)
		printf("NO\n");
	else
	{
		printf("YES\n");
		if(cons==0)
			for(int t=0;t<n;t++)
			for(int i=0;i<3;i++)
				printf("%c",r[i]);
		else
			for(int i=0;i<3;i++)
			for(int t=0;t<n;t++)
				printf("%c",r[i]);
		printf("\n");
	}
	return 0;
}
