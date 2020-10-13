#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	char num[70],ans[70];
	scanf("%s",num);
	if(num[0]=='-'||num[0]=='0')
		cout<<"0"<<endl;
	else
	{
		int len=strlen(num),temp=0;
		ans[len]='\0';
		for(int i=len-1;i>=0;i--)
		{
			temp=(num[i]-'0')*2+temp;
			ans[i]=temp%10+'0';
			temp/=10;
		}//³Ë2 
		ans[len-1]--;
		if(ans[len-1]<'0')
		{
			for(int i=len-1;i>=0;i--)
			{
				ans[i]+=10;
				ans[i-1]--;
				if(ans[i-1]>='0')
					break;
			}
		}//¼õ1 
		if(temp>0)
			printf("%d",temp);
		printf("%s\n",ans);
	}
	return 0;
}
