#include <cstdio>
#include <cstring>
struct bign
{
	int d[1000];
	int len;
	bign()
	{
		memset(d,0,sizeof(d));
		len=0;
	}
};
bign change(char s[])
{
	bign a;
	a.len=strlen(s);
	for(int i=0;i<a.len;i++)
	{
		if(s[a.len-i-1]>='0'&&s[a.len-i-1]<='9')
			a.d[i]=s[a.len-i-1]-'0';
		else if(s[a.len-i-1]>='A'&&s[a.len-i-1]<='Z')
			a.d[i]=s[a.len-i-1]-'A'+10;
	}
	return a;
}
int main()
{
	int m,n;
	while(~scanf("%d %d",&m,&n))
	{
		char a[1000]={'\0'};
		char out[1000]={'\0'};
		scanf("%s",a);
		bign b=change(a);
		int k=b.len,len=b.len,num=0;
		//printf("%d\n",len);
		while(len>0)
		{
			int c=0;
			for(int i=len-1;i>=0;i--)
			{
				int s=(b.d[i]+m*c)/n;
				c=(b.d[i]+m*c)%n;
				b.d[i]=s;
			}
			if(c>=0&&c<=9)
				out[num++]=c+'0';
			if(c>=10&&c<=36)
				out[num++]=c+'a'-10;
			while(b.d[len-1]==0)
				len--;
		}
		for(int i=num-1;i>=0;i--)
			printf("%c",out[i]);
		printf("\n");
	}
	return 0;
}
