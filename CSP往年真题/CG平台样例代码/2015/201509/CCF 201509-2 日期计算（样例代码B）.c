#include <stdio.h>
int isLeap(int y)
{
	if((y%100!=0&&y%4==0)||y%400==0)
		return 1;
	else
		return 0;
}//判断是否为闰年的函数 
int main()
{
	int mon[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};//用数组储存每个月的天数 
	int y,d;//输入的年份和天数 
	scanf("%d%d",&y,&d);
	int month=1,day;//输出的月份和日期 
	if(isLeap(y)==1)
		mon[2]=29;//如果是闰年，将2月份的天数改为29 
	while(1)
	{
		if(d-mon[month]>0)
		{
			d-=mon[month];
			month++;
		}//从1月开始算天数，如果剩余天数比当前月份的天数多，那么剩余天数减去当前月份的天数，月份加1 
		else
		{
			day=d;
			break;
		}//如果剩余天数比当前月份天数少，那么月份就确定为当前月份，日期就确定为剩余天数，退出循环 
	} 
	printf("%d\n%d\n",month,day);
	return 0;
}
