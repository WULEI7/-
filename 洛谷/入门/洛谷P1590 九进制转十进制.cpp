#include <bits/stdc++.h>
using namespace std;
int main()
{
	int i,j,n,weishu,ans;
	char a[11];
	scanf("%d",&n);
	for(j=0;j<n;j++)//用for循环输入n个Pascal数 
	{
		scanf("%s",a);
		weishu=strlen(a);//记录输入数字的位数 
		ans=0;//将数的个数清零 
		for(i=0;i<weishu;i++) 
		{
			if(a[i]=='8'||a[i]=='9') a[i]-=1;//如果位上是8或9则变成7或8 
			ans+=(a[i]-'0')*pow(9,weishu-i-1);//然后相当于九进制转成十进制，例如九进制的123等于十进制的 1*81+2*9+3*1=102 
		}
		printf("%d\n",ans);//输出数的个数 
	}
	return 0;
}
