#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int y,m,d,pos=0;
int month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
struct node
{
	int y,m,d;
}date[6];
bool cmp(node a,node b)
{
	if(a.y!=b.y)
		return a.y<b.y;
	if(a.m!=b.m)
		return a.m<b.m;
	return a.d<b.d;
}
int isleap(int n)
{
	if(n%100!=0&&n%4==0||n%400==0)
		return 1;
	return 0;
}
void check(int a,int b,int c)
{
	if(a>=60)
	{
		y=1900+a;
		if(b>=1&&b<=12)
		{
			m=b;
			if(isleap(y)==0)
			{
				if(c>=1&&c<=month[b])
				{
					d=c;
					date[pos].y=y;
					date[pos].m=m;
					date[pos].d=d;
					pos++;
				}
			}
			else
			{
				month[2]=29;
				if(c>=1&&c<=month[b])
				{
					d=c;
					date[pos].y=y;
					date[pos].m=m;
					date[pos].d=d;
					pos++;
				}
				month[2]=28;
			}
		}
	}
	if(a<=59)
	{
		y=2000+a;
		if(b>=1&&b<=12)
		{
			m=b;
			if(isleap(y)==0)
			{
				if(c>=1&&c<=month[b])
				{
					d=c;
					date[pos].y=y;
					date[pos].m=m;
					date[pos].d=d;
					pos++;
				}
			}
			else
			{
				month[2]=29;
				if(c>=1&&c<=month[b])
				{
					d=c;
					date[pos].y=y;
					date[pos].m=m;
					date[pos].d=d;
					pos++;
				}
				month[2]=28;
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	string s;
	cin>>s;
	int aa,bb,cc;
	aa=(s[0]-'0')*10+s[1]-'0';
	bb=(s[3]-'0')*10+s[4]-'0';
	cc=(s[6]-'0')*10+s[7]-'0';
	//可能：年/月/日，月/日/年，日/月/年 
	//日期在1960年1月1日至2059年12月31日之间 
	check(aa,bb,cc);
	check(cc,aa,bb);
	check(cc,bb,aa);
	sort(date,date+pos,cmp);
	if(pos==0) return 0;
	printf("%d-",date[0].y);
	if(date[0].m>=10)
		printf("%d-",date[0].m);
	else
		printf("0%d-",date[0].m);
	if(date[0].d>=10)
		printf("%d\n",date[0].d);
	else
		printf("0%d\n",date[0].d);
	for(int i=1;i<pos;i++)
		if(!(date[i].y==date[i-1].y&&date[i].m==date[i-1].m&&date[i].d==date[i-1].d))
		{
			printf("%d-",date[i].y);
			if(date[i].m>=10)
				printf("%d-",date[i].m);
			else
				printf("0%d-",date[i].m);
			if(date[i].d>=10)
				printf("%d\n",date[i].d);
			else
				printf("0%d\n",date[i].d);
		}
	return 0;
}
