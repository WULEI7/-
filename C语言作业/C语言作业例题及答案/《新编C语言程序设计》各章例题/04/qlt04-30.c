#include <stdio.h>
#include <time.h>
struct tm *ptm;    //tm结构体见time.h文件
time_t aclock;     //即长整型数
void main( void )
{  char *wday[] = {"Sun","Mon","Tue","Wed","Thu","Fri","Sat"}; //定义一周星期名称
   //time()获取系统时间,从1970年1月1日0 时0分0秒算起至今所经过的秒数
   time(&aclock);
   printf("每年秒数=365*24*60*60 = %ld 秒\n",365*24*60*60); //每年秒数
   printf( "从1970年1月1日0 时0分0秒至今已有 %ld 秒，已约有 %ld 年。\n",aclock,time(&aclock)/(365*24*60*60));
   printf("当前日期与时间是：%s",ctime(&aclock));
   ptm= gmtime(&aclock);  //将aclock中的数值gmtime转换后存于ptm所指结构体
   printf("当前日期与时间是：%s",asctime(ptm)); //把结构体转换成日期时间字符串
   ptm=localtime(&aclock);//将aclock中的数值localtime转换后存于ptm所指结构体
   printf("当前日期与时间是：%s\n",asctime(ptm));//把结构体转换成日期时间字符串
   printf("从1970年以来的秒数  : %ld \n",aclock);
   printf("从1970年以来的小时数: %f \n",(float)aclock/3600.0);
   printf("从1970年以来的天数  : %f \n",(float)aclock/3600.0/24.0);
   printf("从1970年以来的年数  : %f \n\n",(float)aclock/3600.0/24.0/365.0);
   printf("从1900年以来的第 %d 年。\n",ptm->tm_year);
   printf("本月是今年的第 %d 月。\n",1+ptm->tm_mon);
   printf("今天是今年的第 %d 天。\n",ptm->tm_yday);
   printf("今天是本月的第 %d 天。\n",ptm->tm_mday);
   printf("今天是本周的第 %d 天。\n",ptm->tm_wday);
   printf("现在是今天的第 %d 个小时。\n",ptm->tm_hour);
   printf("现在是这个小时的第 %d 分钟。\n",ptm->tm_min);
   printf("现在是这分钟的第 %d 秒。\n",ptm->tm_sec);
   printf("当前夏令时间标记是: %d \n\n",ptm->tm_isdst);
   printf("当前日期与时间：%d-%d-%d ",(1900+ptm->tm_year),(1+ptm->tm_mon),ptm->tm_mday);
   printf("%s %d:%d:%d\n",wday[ptm->tm_wday],ptm->tm_hour,ptm->tm_min,ptm->tm_sec);
}
