#include <bits/stdc++.h>
using namespace std;
int main()
{
	char c,x;//c输入方程，x存未知数的字母 
	int flag=1,lr=1,k=0,b=0,num=0,isnum=0;//flag标记正负，lr表示等号左右，将方程转化为 kx+b=0 的形式，k为未知数系数，b为常数，num存读取的数字，isnum标记是否读到数字 
	float ans=0;
	while(c!='\n')
	{
		c=getchar();//每次读取一个字符，并按照下列判断 
		if(c=='-')
		{
			b+=lr*flag*num;
			num=0;
			flag=-1;
			isnum=0;
		}
		if(c=='+')
		{
			b+=lr*flag*num;
			num=0;
			flag=1;
			isnum=0;
		}
		if(c=='=')
		{
			b+=lr*flag*num;
			num=0;
			flag=1;
			lr=-1;
			isnum=0;
		}
		if(c>='0'&&c<='9')
		{
			num=num*10+c-'0';
			isnum=1;
		}
		if(c>='a'&&c<='z')
		{
			x=c;
			if(isnum)
			{
				k+=lr*flag*num;
				num=0;
			}
			else k+=lr*flag;
			isnum=0;
		}
	}
	b+=lr*flag*num;//若方程最后一项是常数则加入b 
	ans=float(-b*1.0/k);
	if(ans==0) ans=0;//特判 kx=0 k为负数的情况 
	printf("%c=%.3f",x,ans);
	return 0;
}
