#include <stdio.h>
int leap(int n)
{
	int x;
	if((n%4==0&&n%100!=0)||n%400==0) x=1;
	else x=0;
	return x;
}
int main()
{
	int n;
	printf("请输入年份信息：\n"); 
	scanf("%d",&n);
	if(leap(n)) printf("2月份天数是29天\n");
	else printf("2月份天数是28天\n");
	return 0;
}
